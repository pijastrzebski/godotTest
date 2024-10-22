#include "enemybuilder.hpp"

#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/path_follow2d.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/rigid_body2d.hpp"
#include "godot_cpp/classes/timer.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

constexpr auto TIMER_INTERVAL_SEC = 5;
constexpr auto PATH_PROGRESS_SPEED = 100;

void EnemyBuilder::_process(double delta)
{
	if (m_pathFollowLeft)
	{
		m_pathProgress += static_cast<float>(PATH_PROGRESS_SPEED * delta);
		m_pathFollowLeft->set_progress(m_pathProgress);
	}
}

void EnemyBuilder::_ready()
{
	auto timer = get_node<Timer>("SpawnTimer");
	if (timer)
	{
		timer->connect("timeout", Callable(this, "onTimeout"));
		timer->start(TIMER_INTERVAL_SEC);
	}

	m_pathFollowLeft = get_node<PathFollow2D>("EnemyPaths/EnemyPathLeft/PathFollow");
}

void EnemyBuilder::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("onTimeout"), &EnemyBuilder::onTimeout);
}

void EnemyBuilder::onTimeout()
{
	UtilityFunctions::print("onTimeout 1 sec...");

	// spawn enemy
	UtilityFunctions::print("spawn enemy");
	Ref<PackedScene> enemy = ResourceLoader::get_singleton()->load("res://scenes/enemy.tscn");
	if (enemy->can_instantiate())
	{
		if (auto pathFollow = get_node<PathFollow2D>("EnemyPaths/EnemyPathLeft/PathFollow"); pathFollow)
		{
			auto enemyNode = enemy->instantiate();
			auto sprite = enemyNode->get_node<AnimatedSprite2D>("Sprite");
			if (sprite)
			{
				sprite->set_animation("idle");
				sprite->set_flip_h(true);
			}
			pathFollow->add_child(enemyNode);
		}
	}
}
