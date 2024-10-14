#pragma once

#include "godotcustomcontrol.hpp"

using namespace godot;

class Options : public GodotCustomControl
{
	GDCLASS(Options, GodotCustomControl)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void getInput();

private:
	bool m_keyPressed = false;
};
