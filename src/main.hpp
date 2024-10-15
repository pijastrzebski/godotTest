#pragma once

#include "godot_cpp/classes/node2d.hpp"

using namespace godot;

class Main : public Node2D
{
	GDCLASS(Main, Node2D)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

};
