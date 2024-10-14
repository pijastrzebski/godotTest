#include "optionsbutton.hpp"

#include "options.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void OptionsButton::_process(double delta)
{
}

void OptionsButton::_ready()
{
	UtilityFunctions::print("OptionsButton _ready()");

	connect("pressed", Callable(this, "showOptions"));
}

void OptionsButton::_bind_methods()
{
	UtilityFunctions::print("OptionsButton bind fckn methods");

	ClassDB::bind_method(D_METHOD("showOptions"), &OptionsButton::showOptions);
}

void OptionsButton::showOptions()
{
	Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/options.tscn");
	if (ref->can_instantiate())
	{
		m_options = ref->instantiate();
		get_parent()->add_child(m_options);
		cast_to<Options>(m_options)->set_visible(true);
		m_options->connect("tree_exited", Callable(this, "closeOptions"));
		ClassDB::bind_method(D_METHOD("closeOptions"), &OptionsButton::closeOptions);
	}
}

void OptionsButton::closeOptions()
{
	m_options = nullptr;
}
