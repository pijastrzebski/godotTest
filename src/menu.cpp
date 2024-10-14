#include "menu.hpp"

#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void Menu::_process(double delta)
{
	getInput();
}

void Menu::_ready()
{
	UtilityFunctions::print("Menu ready()");

	set_visible(true);
}

void Menu::_bind_methods()
{
}

void Menu::getInput()
{

	UtilityFunctions::print("Menu getInput()");

	//auto escape = Input::get_singleton()->is_key_pressed(KEY_ESCAPE);

	//if (escape)
	//{
	//	queue_free();
	//}
}
