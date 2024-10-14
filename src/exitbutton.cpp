#include "exitbutton.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void ExitButton::_process(double delta)
{
}

void ExitButton::_ready()
{
	connect("pressed", Callable(this, "exit"));
}

void ExitButton::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("exit"), &ExitButton::exit);
}

void ExitButton::exit()
{
	UtilityFunctions::print("ExitButton exit()");
	get_tree()->quit();
}
