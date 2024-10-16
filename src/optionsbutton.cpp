#include "optionsbutton.hpp"

#include "options.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void OptionsButton::_process(double delta)
{
}

void OptionsButton::_ready()
{
	connect("pressed", Callable(this, "showOptions"));
}

void OptionsButton::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("showOptions"), &OptionsButton::showOptions);
}

void OptionsButton::showOptions()
{
	closeOptions();

	Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/options.tscn");
	if (ref->can_instantiate())
	{
		auto options = ref->instantiate();
		get_parent()->add_child(options);
	}
}

void OptionsButton::closeOptions()
{
	auto options = get_node_or_null("/root/Main/Menu/VBoxContainer/Options");

	if (options)
	{
		options->get_parent()->remove_child(options);
		options->queue_free();
	}
}
