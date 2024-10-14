#pragma once

#include <godot_cpp/classes/sprite2d.hpp>

using namespace godot;

class GodotCustomSprite : public Sprite2D
{
	GDCLASS(GodotCustomSprite, Sprite2D)

public:
	GodotCustomSprite();

	void _process(double delta) override;

protected:
	static void _bind_methods();

	double getAmplitude();
	void setAmplitude(double amplitude);

private:
	double m_timePassed = 0;
	double m_amplitude = 10.0;
};
