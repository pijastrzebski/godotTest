#include "bunker.hpp"

#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/physics_server2d.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void Bunker::getInput()
{
	auto right = Input::get_singleton()->is_key_pressed(KEY_RIGHT);
	auto left = Input::get_singleton()->is_key_pressed(KEY_LEFT);
	auto up = Input::get_singleton()->is_key_pressed(KEY_UP);
	auto down = Input::get_singleton()->is_key_pressed(KEY_DOWN);

	if (up)
	{
		UtilityFunctions::print("Bunker::getInput up");
	}
	if (right)
	{
		UtilityFunctions::print("Bunker::getInput right");
	}
	if (left)
	{
		UtilityFunctions::print("Bunker::getInput left");
	}
	if (down)
	{
		UtilityFunctions::print("Bunker::getInput down");
	}
}

Bunker::Bunker()
{
}

void Bunker::_physics_process(double delta)
{
	getInput();
}

void Bunker::_ready()
{
}

void Bunker::_bind_methods()
{
}
