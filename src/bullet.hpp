#pragma once

#include "godot_cpp/classes/character_body2d.hpp"

using namespace godot;

class Bullet : public CharacterBody2D
{
	GDCLASS(Bullet, CharacterBody2D)

public:
	Bullet() = default;

	void _physics_process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

private:
	Vector2 m_velocity;
	Vector2 m_direction;
	Vector2 m_position;
};
