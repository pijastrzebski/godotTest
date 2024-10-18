#pragma once

#include "godot_cpp/classes/character_body2d.hpp"

using namespace godot;

class MachineGun : public CharacterBody2D
{
	GDCLASS(MachineGun, CharacterBody2D)

public:
	enum EDirection
	{
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

	MachineGun();

	void _physics_process(double delta) override;
	void _ready() override;

	EDirection getDirection() const { return m_direction; }
protected:
	static void _bind_methods();

	void getInput();

private:
	bool m_shootReady = true;
	EDirection m_direction = EDirection::RIGHT;
};
