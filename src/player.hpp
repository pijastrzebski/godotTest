#pragma once

#include "godot_cpp/classes/node2d.hpp"

using namespace godot;

class Player : public Node2D
{
	GDCLASS(Player, Node2D)

	struct Stats
	{
		double maxHP = 100;
		double hp = 100;
		double xpToNextLevel = 100;
		double xp = 0;
	};

public:
	void _process(double delta) override;
	void _ready() override;

	void adjustHP(double hp);

protected:
	static void _bind_methods();

private:
	void updateHPBar(double hp);
	void updateXPBar(double xp);

	Stats m_stats;
};
