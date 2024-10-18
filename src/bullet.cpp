#include "bullet.hpp"

#include "machinegun.hpp"

constexpr auto SPEED = 200;

void Bullet::_physics_process(double delta)
{
	m_velocity.x += m_direction * static_cast<real_t>(SPEED * delta);
	set_velocity(m_velocity);
	move_and_slide();
}

void Bullet::_ready()
{
	auto machineGun = cast_to<MachineGun>(get_parent());

	switch (machineGun->getDirection())
	{
	case MachineGun::LEFT: {
		m_direction = -1;
		break;
	}
	case MachineGun::UP:
	{
		m_direction = 0; // todo
		break;

	}
	case MachineGun::DOWN:
	{
		m_direction = 0; // todo
		break;
	}

	case MachineGun::RIGHT:
	{
		m_direction = 1;
		break;
	}
	}
}

void Bullet::_bind_methods()
{
}
