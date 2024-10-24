#pragma once

#include "godot_cpp/classes/animatable_body2d.hpp"
#include "godot_cpp/classes/area2d.hpp"

using namespace godot;

class Bunker : public AnimatableBody2D
{
	GDCLASS(Bunker, AnimatableBody2D)

public:
	Bunker();

	void _physics_process(double delta) override;
	void _ready() override;
protected:
	static void _bind_methods();

	void getInput();
private:
	void onCollision(Area2D* area);
	void onMouseEntered();
};
