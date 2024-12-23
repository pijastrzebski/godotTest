#include "machinegun.hpp"

#include "bullet.hpp"
#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/marker2d.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/physics_server2d.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

constexpr auto ROTATE_SPEED = 50;

void MachineGun::getInput(float delta)
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
		auto angle = ROTATE_SPEED * delta;
		auto sprite = get_node<AnimatedSprite2D>("Sprite/Head");
		sprite->rotate(Math::deg_to_rad(angle));
		m_angle = sprite->get_rotation_degrees();
	}
	if (left)
	{
		UtilityFunctions::print("MachineGun::getInput left");
		auto angle = -1.f * ROTATE_SPEED * delta;
		auto sprite = get_node<AnimatedSprite2D>("Sprite/Head");
		sprite->rotate(Math::deg_to_rad(angle));
		m_angle = sprite->get_rotation_degrees();
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
		// rotate / set pos
		auto bullet = cast_to<Bullet>(ref->instantiate());
		auto startPos = get_node<Marker2D>("Sprite/StartPos");
		//Vector2 direction = Vector2(cos(Math::deg_to_rad(m_angle)), sin(Math::deg_to_rad(m_angle)));
		//bullet->set_position(direction); // todo: improve start position of the bullet
		bullet->set_position(startPos->get_position());
		bullet->rotate(Math::deg_to_rad(m_angle + 90.f));
		// add the node
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
	getInput(static_cast<float>(delta));
}

void MachineGun::_ready()
{
}

void MachineGun::_bind_methods()
{
}
