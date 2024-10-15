#include "game.hpp"

#include "menu.hpp"
#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void Game::_process(double delta)
{
	getInput();
}

void Game::_ready()
{
}

void Game::_bind_methods()
{
}

void Game::getInput()
{
	// check key
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

	// handle each key
	if (escape)
	{
		auto menu = get_node<Menu>("/root/Main/Menu");
		if (!menu)
		{
			UtilityFunctions::print("menu detected");
			// make this scene transparent
			auto canvas = cast_to<CanvasItem>(this);
			if (canvas)
			{
				canvas->set_modulate(Color(1, 1, 1, 0.2f));
			}

			// todo: pause all related nodes

			// create menu
			Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/menu.tscn");
			if (ref->can_instantiate())
			{
				get_parent()->add_child(ref->instantiate());
			}
		}
		else
		{
			UtilityFunctions::print("there's no menu");
			restoreOpacity();

			// clean menu
			menu->get_parent()->remove_child(menu);
			menu->queue_free();
		}
		m_keyPressed = true;
	}
}

void Game::restoreOpacity()
{
	auto canvas = cast_to<CanvasItem>(this);
	if (canvas)
	{
		canvas->set_modulate(Color(1, 1, 1, 1));
	}
}
