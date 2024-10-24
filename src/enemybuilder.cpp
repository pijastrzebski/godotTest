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
constexpr auto TIMER_ONE_SHOT_ENABLED = true;

void EnemyBuilder::_process(double delta)
{
}

void EnemyBuilder::_ready()
{
	auto timer = get_node<Timer>("SpawnTimer");
	if (timer)
	{
		timer->connect("timeout", Callable(this, "onTimeout"));
		timer->start(TIMER_INTERVAL_SEC);
		timer->set_one_shot(TIMER_ONE_SHOT_ENABLED);
	}
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
		auto enemyNode = cast_to<Enemy>(enemy->instantiate());
		// set animation
		if (auto sprite = enemyNode->get_node<AnimatedSprite2D>("Sprite"); sprite)
		{
			sprite->play("idle");
			sprite->set_flip_h(true);
		}

		// create a path for the enemy
		Ref<PackedScene> path = ResourceLoader::get_singleton()->load("res://scenes/enemy-paths.tscn");
		if (path->can_instantiate())
		{
			auto pathNode = path->instantiate();
			get_parent()->add_child(pathNode);
			enemyNode->setPath(pathNode);
			if (auto pathFollow = enemyNode->getPathFollow(); pathFollow)
			{
				pathFollow->add_child(enemyNode);
			}
		}
	}
}
