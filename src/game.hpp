#pragma once

#include "godot_cpp/classes/node2d.hpp"

using namespace godot;

class Game : public Node2D
{
	GDCLASS(Game, Node2D)

public:
	Game();

	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void getInput(float delta);

private:
	void restoreOpacity();
	void restoreCamera();

	bool m_keyPressed;
	Vector2 m_cameraZoom;
	Vector2 m_cameraOffset;
};
