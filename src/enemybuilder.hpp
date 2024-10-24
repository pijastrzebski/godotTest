#pragma once

#include "godot_cpp/classes/path_follow2d.hpp"

using namespace godot;

class EnemyBuilder : public Node2D
{
	GDCLASS(EnemyBuilder, Node2D)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void onTimeout();

private:
};
