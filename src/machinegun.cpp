#include "machinegun.hpp"

#include "bullet.hpp"
#include "godot_cpp/classes/character_body2d.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/marker2d.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/physics_server2d.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void MachineGun::getInput()
{
	auto right = Input::get_singleton()->is_key_pressed(KEY_RIGHT);
	auto left = Input::get_singleton()->is_key_pressed(KEY_LEFT);
	auto up = Input::get_singleton()->is_key_pressed(KEY_UP);
	auto down = Input::get_singleton()->is_key_pressed(KEY_DOWN);
	auto shoot = Input::get_singleton()->is_key_pressed(KEY_SPACE);

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
	if (shoot & m_shootReady)
	{
		UtilityFunctions::print("MachineGun::getInput shot");
		// create bullet
		Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/bullet.tscn");
		auto bullet = cast_to<Bullet>(ref->instantiate());
		auto startPos = get_node<Marker2D>("StartPos");
		bullet->rotate(Math::deg_to_rad(90.f));
		bullet->set_position(startPos->get_position());
		add_child(bullet);
		m_shootReady = false;
	}

	if (!m_shootReady)
	{
		if (!Input::get_singleton()->is_anything_pressed())
		{
			m_shootReady = true;
		}
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
