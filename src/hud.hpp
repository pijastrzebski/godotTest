#pragma once

#include "godot_cpp/classes/control.hpp"

using namespace godot;

class HUD : public Control
{
	GDCLASS(HUD, Control)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void getInput();

};
