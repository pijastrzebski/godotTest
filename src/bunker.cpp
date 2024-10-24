#include "bunker.hpp"

#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/physics_server2d.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

Bunker::Bunker()
{
}

void Bunker::_physics_process(double delta)
{
	getInput();
}

void Bunker::_ready()
{
	auto detectionArea = get_node<Area2D>("DetectionArea");
	if (detectionArea)
	{
		detectionArea->connect("area_entered", Callable(this, "onCollision"));
		detectionArea->connect("mouse_entered", Callable(this, "bunker onMouseEntered"));
	}
}

void Bunker::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("onCollision", "area"), &Bunker::onCollision);
	ClassDB::bind_method(D_METHOD("onMouseEntered"), &Bunker::onMouseEntered);
}

void Bunker::getInput()
{
	auto right = Input::get_singleton()->is_key_pressed(KEY_RIGHT);
	auto left = Input::get_singleton()->is_key_pressed(KEY_LEFT);
	auto up = Input::get_singleton()->is_key_pressed(KEY_UP);
	auto down = Input::get_singleton()->is_key_pressed(KEY_DOWN);

	if (up)
	{
		UtilityFunctions::print("Bunker::getInput up");
	}
	if (right)
	{
		UtilityFunctions::print("Bunker::getInput right");
	}
	if (left)
	{
		UtilityFunctions::print("Bunker::getInput left");
	}
	if (down)
	{
		UtilityFunctions::print("Bunker::getInput down");
	}
}

void Bunker::onCollision(Area2D* area)
{
	UtilityFunctions::print("bunker collision detected with: ", area->get_parent()->get_name());
}

void Bunker::onMouseEntered()
{
	UtilityFunctions::print("on mouse entered");
}
