#include "godotcustomcharacterbody.hpp"

#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/physics_server2d.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

constexpr auto RUN_SPEED = 350;
constexpr auto JUMP_SPEED = -1000;
constexpr auto GRAVITY = 2500.0; // u can also get the gravity by calling: ProjectSettings::get_singleton()->get_setting("physics/2d/default_gravity")

void GodotCustomCharacterBody::getInput()
{
	m_velocity.x = 0;
	auto right = Input::get_singleton()->is_key_pressed(KEY_RIGHT);
	auto left = Input::get_singleton()->is_key_pressed(KEY_LEFT);
	auto jump = Input::get_singleton()->is_key_pressed(KEY_UP);
	auto down = Input::get_singleton()->is_key_pressed(KEY_DOWN);

	if (is_on_floor() && jump)
	{
		m_velocity.y = JUMP_SPEED;
		UtilityFunctions::print("GodotCustomCharacterBody::getInput jump");
	}
	if (right)
	{
		m_velocity.x += RUN_SPEED;
		UtilityFunctions::print("GodotCustomCharacterBody::getInput right");
	}
	if (left)
	{
		m_velocity.x -= RUN_SPEED;
		UtilityFunctions::print("GodotCustomCharacterBody::getInput left");
	}
	if (down)
	{
		emit_signal("velocityChanged", m_velocity);
		UtilityFunctions::print("GodotCustomCharacterBody::getInput down");
	}
}

GodotCustomCharacterBody::GodotCustomCharacterBody() :
	m_velocity(Vector2(250, 250))
{
}

void GodotCustomCharacterBody::_physics_process(double delta)
{
	m_velocity.y += static_cast<real_t>(GRAVITY * delta);
	getInput();
	set_velocity(m_velocity);
	move_and_slide();
}

void GodotCustomCharacterBody::_ready()
{
	UtilityFunctions::print("GodotCustomCharacterBody _ready()");
	
	connect("velocityChanged", Callable(this, "onVelocityChanged"));
}

void GodotCustomCharacterBody::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("onVelocityChanged"), &GodotCustomCharacterBody::onVelocityChanged);

	ADD_SIGNAL(MethodInfo("velocityChanged", PropertyInfo(Variant::VECTOR2, "velocity")));
}

void GodotCustomCharacterBody::onVelocityChanged(Vector2 velocity)
{
	UtilityFunctions::print("GodotCustomCharacterBody::onVelocityChanged velocity = ", velocity);
}
