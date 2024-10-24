#include "enemy.hpp"

#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

constexpr auto PATH_PROGRESS_SPEED = 100;

Enemy::Enemy()
{
}

void Enemy::_physics_process(double delta)
{
	if (auto pathFollow = getPathFollow(); pathFollow)
	{
		m_pathProgress += static_cast<float>(PATH_PROGRESS_SPEED * delta);
		pathFollow->set_progress(m_pathProgress);
	}
}

void Enemy::_ready()
{
	// setup connects
	if (auto detectionArea = get_node<Area2D>("DetectionArea"); detectionArea)
	{
		detectionArea->connect("area_entered", Callable(this, "onCollision"));
	}
}

void Enemy::setPath(Node* path)
{
	m_path = path;
}

void Enemy::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("onCollision", "area"), &Enemy::onCollision);
}

void Enemy::onCollision(Area2D* area)
{
	if (!area)
	{
		return;
	}

	// collision effects
	auto areaName = area->get_parent()->get_name();
	UtilityFunctions::print("enemy collision detected with: ", areaName);
	
	if (auto sprite = get_node<AnimatedSprite2D>("Sprite"); sprite)
	{
		if (areaName.contains("Bullet"))
		{
			UtilityFunctions::print("got hit by bullet");
			get_parent()->queue_free();
		}
		else if (areaName.contains("Bunker")) {
			UtilityFunctions::print("enemy attacks");
			sprite->play("attack");
		}
		else if (areaName.contains("Enemy"))
		{
			UtilityFunctions::print("enemy touches another enemy ...");
		}
	}
}

PathFollow2D* Enemy::getPathFollow() const
{
	if (!m_path)
	{
		return nullptr;
	}

	return m_path->get_node<PathFollow2D>("EnemyPathLeft/PathFollow");
}
