#pragma once

#include "godot_cpp/classes/control.hpp"

using namespace godot;

class Menu : public Control
{
	GDCLASS(Menu, Control)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();
};
