#pragma once

#include <godot_cpp/classes/animated_sprite2d.hpp>

using namespace godot;

class GodotCustomAnimatedSprite : public AnimatedSprite2D
{
	GDCLASS(GodotCustomAnimatedSprite, AnimatedSprite2D)

public:
	GodotCustomAnimatedSprite();

	void _process(double delta) override;
	void _physics_process(double delta) override;

protected:
	static void _bind_methods();

	double getAmplitude();
	void setAmplitude(double amplitude);

private:
	double m_timePassed = 0;
	double m_amplitude = 0;
};
