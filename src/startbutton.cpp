#include "startbutton.hpp"

#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void StartButton::_process(double delta)
{
}

void StartButton::_ready()
{
	UtilityFunctions::print("StartButton is ready");

	connect("pressed", Callable(this, "start"));

}

void StartButton::_bind_methods() 
{
	ClassDB::bind_method(D_METHOD("start"), &StartButton::start);
}

void StartButton::start()
{
	UtilityFunctions::print("start()");

	get_tree()->change_scene_to_file("res://scenes/game.tscn");

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
