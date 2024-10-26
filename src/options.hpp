#pragma once

#include "godot_cpp/classes/control.hpp"

using namespace godot;

class Options : public Control
{
	GDCLASS(Options, Control)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void getInput();

private:
	bool m_keyPressed = false;
};
