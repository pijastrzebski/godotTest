#pragma once
#include "godot_cpp/classes/control.hpp"

using namespace godot;

class GodotCustomControl : public Control
{
	GDCLASS(GodotCustomControl, Control)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

};
