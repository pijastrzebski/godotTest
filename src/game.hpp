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

	void getInput(double delta);

private:
	void restoreOpacity();

	bool m_keyPressed = false;
	Vector2 m_cameraZoom = Vector2(1, 1);
	Vector2 m_cameraOffset = Vector2(0, 0);
};
