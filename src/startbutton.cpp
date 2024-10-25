#include "startbutton.hpp"

#include "game.hpp"
#include "menu.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/window.hpp"

void StartButton::_process(double delta)
{
}

void StartButton::_ready()
{
	connect("pressed", Callable(this, "start"));
}

void StartButton::_bind_methods() 
{
	ClassDB::bind_method(D_METHOD("start"), &StartButton::start);
}

void StartButton::start()
{
	closeGame();

	Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/game.tscn");
	if (ref->can_instantiate())
	{
		// add created node
		auto game = ref->instantiate();
		auto mainNode = get_node<Node2D>("/root/Main");
		mainNode->add_child(game);

		auto menuNode = get_node<Menu>("/root/Main/Menu");
		menuNode->get_parent()->remove_child(menuNode);
		menuNode->queue_free();
	}


	// how to switch scenes?

	//hide();// uses mem + cpu

	//get_tree()->change_scene_to_file(...);// cleans mem, does not use cpu

	// remove node from three// uses mem, does not use cpu
	//auto node = get_node<class_name>();
	//get_tree()->get_root()->remove_child(node);

	// load a simultaneous scene
	//ResourceLoader* reLo = ResourceLoader::get_singleton();
	//Ref<PackedScene> ref = reLo->load("res://scenes/game.tscn");
	//if (ref->can_instantiate())
	//{
	//	auto nextNode = ref->instantiate();
	//	add_child(nextNode);
	//	cast_to<Game>(nextNode)->set_visible(true);
	//}
}

void StartButton::closeGame()
{
	if (auto game = get_node_or_null("/root/Main/Game"); game)
	{
		game->get_parent()->remove_child(game);
		game->queue_free();
	}
}
