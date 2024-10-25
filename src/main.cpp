#include "main.hpp"

#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/resource_loader.hpp"

void Main::_process(double delta)
{
}

void Main::_ready()
{
	Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/menu.tscn");
	if (ref->can_instantiate())
	{
		add_child(ref->instantiate());
	}
}

void Main::_bind_methods()
{
}
