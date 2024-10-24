#include "enemybuilder.hpp"

#include "enemy.hpp"
#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/path2d.hpp"
#include "godot_cpp/classes/path_follow2d.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
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
		timer->set_one_shot(false);
	}

	m_pathFollowLeft = get_node<PathFollow2D>("EnemyPaths/EnemyPathLeft/PathFollow");
}

void EnemyBuilder::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("onTimeout"), &EnemyBuilder::onTimeout);
}

void EnemyBuilder::onTimeout()
{
	UtilityFunctions::print("onTimeout ", TIMER_INTERVAL_SEC, " sec...");

	UtilityFunctions::print("spawn enemy");
	Ref<PackedScene> enemy = ResourceLoader::get_singleton()->load("res://scenes/enemy.tscn");
	if (enemy->can_instantiate())
	{
		auto enemyNode = enemy->instantiate();
		// set animation
		if (auto sprite = enemyNode->get_node<AnimatedSprite2D>("Sprite"); sprite)
		{
			sprite->play("idle");
			sprite->set_flip_h(true);
		}

		// make enemy follow the path
		//cast_to<Enemy>(enemyNode)->setPath(pathNode);
		//auto pathFollowLeft = get_node<PathFollow2D>("EnemyPaths/EnemyPathLeft/PathFollow");
		m_pathFollowLeft->add_child(enemyNode);
		m_pathProgress = 0;
	}
}
