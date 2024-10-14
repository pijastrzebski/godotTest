#pragma once

#include "godot_cpp/classes/button.hpp"

using namespace godot;

class GodotCustomButton : public Button
{
	GDCLASS(GodotCustomButton, Button)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

};
