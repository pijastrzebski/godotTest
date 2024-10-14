#pragma once

#include "godot_cpp/classes/character_body2d.hpp"

using namespace godot;

class GodotCustomCharacterBody : public CharacterBody2D
{
	GDCLASS(GodotCustomCharacterBody, CharacterBody2D)

public:
	GodotCustomCharacterBody();

	void _physics_process(double delta) override;
	void _ready() override;
protected:
	static void _bind_methods();

	void onVelocityChanged(Vector2 velocity);

	void getInput();
private:
	Vector2 m_velocity;
};
