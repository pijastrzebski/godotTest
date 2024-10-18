#include "machinegun.hpp"

#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/physics_server2d.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void MachineGun::getInput()
{
	auto right = Input::get_singleton()->is_key_pressed(KEY_RIGHT);
	auto left = Input::get_singleton()->is_key_pressed(KEY_LEFT);
	auto up = Input::get_singleton()->is_key_pressed(KEY_UP);
	auto down = Input::get_singleton()->is_key_pressed(KEY_DOWN);

	if (up)
	{
		UtilityFunctions::print("MachineGun::getInput up");
	}
	if (right)
	{
		UtilityFunctions::print("MachineGun::getInput right");
	}
	if (left)
	{
		UtilityFunctions::print("MachineGun::getInput left");
	}
	if (down)
	{
		UtilityFunctions::print("MachineGun::getInput down");
	}
}

MachineGun::MachineGun()
{
}

void MachineGun::_physics_process(double delta)
{
	getInput();
}

void MachineGun::_ready()
{
}

void MachineGun::_bind_methods()
{
}
