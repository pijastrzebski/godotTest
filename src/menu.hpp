#pragma once

#include "godotcustomcontrol.hpp"

using namespace godot;

class Menu : public GodotCustomControl
{
	GDCLASS(Menu, GodotCustomControl)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void getInput();

};
