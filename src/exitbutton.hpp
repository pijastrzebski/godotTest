#pragma once

#include "godot_cpp/classes/button.hpp"

using namespace godot;

class ExitButton : public Button
{
	GDCLASS(ExitButton, Button)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void exit();

};
