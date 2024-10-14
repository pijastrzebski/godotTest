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
	UtilityFunctions::print("Game getInput()");

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
		if (!m_menu)
		{
			// make scene transparent
			auto currentScene = get_tree()->get_current_scene();
			auto canvas = cast_to<CanvasItem>(currentScene);
			if (canvas)
			{
				canvas->set_modulate(Color(1, 1, 1, 0.2f));
			}

			// todo: pause all related nodes

			// create menu
			Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/menu.tscn");
			if (ref->can_instantiate())
			{
				m_menu = ref->instantiate();
				get_parent()->add_child(m_menu);
				cast_to<Menu>(m_menu)->set_visible(true);
				m_menu->connect("tree_exited", Callable(this, "restoreOpacity"));
				ClassDB::bind_method(D_METHOD("restoreOpacity"), &Game::restoreOpacity);
			}
		}
		else
		{
			// clean menu
			m_menu->queue_free();
			m_menu = nullptr;
		}
		m_keyPressed = true;
	}
}

void Game::restoreOpacity()
{
	auto currentScene = get_tree()->get_current_scene();
	auto canvas = cast_to<CanvasItem>(currentScene);
	if (canvas)
	{
		canvas->set_modulate(Color(1, 1, 1, 1));
	}
}
