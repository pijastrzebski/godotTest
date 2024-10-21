#include "bullet.hpp"

#include "machinegun.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

constexpr auto SPEED = 200;

void Bullet::_physics_process(double delta)
{
	m_velocity = m_direction * SPEED * delta;
	auto collide = move_and_collide(m_velocity);
	if (collide.is_valid())
	{
		UtilityFunctions::print("collide");
	}
}

void Bullet::_ready()
{
	auto machineGun = cast_to<MachineGun>(get_parent());
	auto angle_radians = static_cast<float>(Math::deg_to_rad(machineGun->getAngle()));
	m_direction = Vector2(cos(angle_radians), sin(angle_radians));
}

void Bullet::_bind_methods()
{
}
