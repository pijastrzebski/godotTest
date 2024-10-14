#pragma once

#include "godotcustombutton.hpp"

using namespace godot;

class StartButton : public GodotCustomButton
{
	GDCLASS(StartButton, GodotCustomButton)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void start();

};
