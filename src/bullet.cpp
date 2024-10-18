#include "bullet.hpp"

constexpr auto SPEED = 200;

void Bullet::_physics_process(double delta)
{
	m_velocity.x += static_cast<real_t>(SPEED * delta);
	set_velocity(m_velocity);
	move_and_slide();
}

void Bullet::_ready()
{
}

void Bullet::_bind_methods()
{
}
