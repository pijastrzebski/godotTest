#pragma once

#include "godot_cpp/classes/animatable_body2d.hpp"

using namespace godot;

class MachineGun : public AnimatableBody2D
{
	GDCLASS(MachineGun, AnimatableBody2D)

public:
	MachineGun();

	void _physics_process(double delta) override;
	void _ready() override;
protected:
	static void _bind_methods();

	void getInput();
private:
};
