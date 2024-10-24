#include "options.hpp"

#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/scene_tree.hpp"

void Options::_process(double delta)
{
	getInput();
}

void Options::_ready()
{
}

void Options::_bind_methods()
{
}

void Options::getInput()
{
	auto escape = Input::get_singleton()->is_key_pressed(KEY_ESCAPE);

	// handle key pressed -> if previously pressed
	if (m_keyPressed)
	{
		// nothing now pressed
		if (!Input::get_singleton()->is_anything_pressed())
		{
			m_keyPressed = false;
		}
		else
		{
			// skip it
			return;
		}
	}

	if (escape)
	{
		// clean menu
		get_parent()->remove_child(this);
		queue_free();
		m_keyPressed = true;
	}
}
