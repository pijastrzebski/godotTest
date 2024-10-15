#pragma once

#include "godotcustomcontrol.hpp"

using namespace godot;

class Options : public GodotCustomControl
{
	GDCLASS(Options, GodotCustomControl)

public:
	static inline Node* s_instance = nullptr;

	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void getInput();

private:
	bool m_keyPressed = false;
};
