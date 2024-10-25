#pragma once

#include "godot_cpp/classes/canvas_layer.hpp"

using namespace godot;

class HUD : public CanvasLayer
{
	GDCLASS(HUD, CanvasLayer)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void getInput();

};
