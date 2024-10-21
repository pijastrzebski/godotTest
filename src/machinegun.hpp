#pragma once

#include "godot_cpp/classes/character_body2d.hpp"

using namespace godot;

class MachineGun : public CharacterBody2D
{
	GDCLASS(MachineGun, CharacterBody2D)

public:
	MachineGun();

	void _physics_process(double delta) override;
	void _ready() override;

	double getAngle() const { return m_angle; }
protected:
	static void _bind_methods();

	void getInput(double delta);

private:
	bool m_shootReady = true;
	double m_angle = 0;
};
