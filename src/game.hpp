#pragma once

#include "godot_cpp/classes/node2d.hpp"

using namespace godot;

class Game : public Node2D
{
	GDCLASS(Game, Node2D)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void getInput();

private:
	void restoreOpacity();

	bool m_keyPressed = false;
};
