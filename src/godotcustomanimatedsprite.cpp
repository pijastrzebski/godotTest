#include "godotcustomanimatedsprite.hpp"

#include "godot_cpp/variant/utility_functions.hpp"

GodotCustomAnimatedSprite::GodotCustomAnimatedSprite()
{
}

void GodotCustomAnimatedSprite::_process(double delta)
{
}

void GodotCustomAnimatedSprite::_physics_process(double delta)
{
}

void GodotCustomAnimatedSprite::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("getAmplitude"), &GodotCustomAnimatedSprite::getAmplitude);
	ClassDB::bind_method(D_METHOD("setAmplitude"), &GodotCustomAnimatedSprite::setAmplitude);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "setAmplitude", "getAmplitude");
}

double GodotCustomAnimatedSprite::getAmplitude()
{
	return m_amplitude;
}

void GodotCustomAnimatedSprite::setAmplitude(double amplitude)
{
	m_amplitude = amplitude;
}
