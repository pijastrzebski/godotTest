#include "game.hpp"

#include "hud.hpp"
#include "main.hpp"
#include "menu.hpp"
#include "title.hpp"
#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/camera2d.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/path_follow2d.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

constexpr auto ZOOM_SPEED = 1;
constexpr auto OFFSET_SPEED = 500;
constexpr auto DEFAULT_CAMERA_OFFSET_X = 0;
constexpr auto DEFAULT_CAMERA_OFFSET_Y = 150;
constexpr auto DEFAULT_CAMERA_ZOOM_X = 1;
constexpr auto DEFAULT_CAMERA_ZOOM_Y = 1;

Game::Game() :
	m_keyPressed(false),
	m_cameraZoom(Vector2(DEFAULT_CAMERA_ZOOM_X, DEFAULT_CAMERA_ZOOM_Y)),
	m_cameraOffset(Vector2(DEFAULT_CAMERA_OFFSET_X, DEFAULT_CAMERA_OFFSET_Y))
{
}

void Game::_process(double delta)
{
	getInput(static_cast<float>(delta));
}

void Game::_ready()
{
	restoreOpacity();
	restoreCamera();
}

void Game::_bind_methods()
{
}

void Game::getInput(float delta)
{
	// check key
	auto f10 = Input::get_singleton()->is_key_pressed(KEY_F10);
	auto q = Input::get_singleton()->is_key_pressed(KEY_Q);
	auto e = Input::get_singleton()->is_key_pressed(KEY_E);
	auto w = Input::get_singleton()->is_key_pressed(KEY_W);
	auto s = Input::get_singleton()->is_key_pressed(KEY_S);
	auto a = Input::get_singleton()->is_key_pressed(KEY_A);
	auto d = Input::get_singleton()->is_key_pressed(KEY_D);

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
	if (q)
	{
		m_cameraZoom.x += delta * ZOOM_SPEED;
		m_cameraZoom.y += delta * ZOOM_SPEED;
		auto camera = get_node<Camera2D>("Camera2D");
		camera->set_zoom(m_cameraZoom);
		UtilityFunctions::print("camera zoom in = ", m_cameraZoom);
	}
	if (e)
	{
		m_cameraZoom.x -= delta * ZOOM_SPEED;
		m_cameraZoom.y -= delta * ZOOM_SPEED;
		auto camera = get_node<Camera2D>("Camera2D");
		camera->set_zoom(m_cameraZoom);
		UtilityFunctions::print("camera zoom out = ", m_cameraZoom);
	}
	if (w)
	{
		m_cameraOffset.y -= delta * OFFSET_SPEED;
		auto camera = get_node<Camera2D>("Camera2D");
		camera->set_offset(m_cameraOffset);
		UtilityFunctions::print("camera change offset up = ", m_cameraOffset);
	}
	if (s)
	{
		m_cameraOffset.y += delta * OFFSET_SPEED;
		auto camera = get_node<Camera2D>("Camera2D");
		camera->set_offset(m_cameraOffset);
		UtilityFunctions::print("camera change offset down = ", m_cameraOffset);
	}
	if (a)
	{
		m_cameraOffset.x -= delta * OFFSET_SPEED;
		auto camera = get_node<Camera2D>("Camera2D");
		camera->set_offset(m_cameraOffset);
		UtilityFunctions::print("camera change offset left = ", m_cameraOffset);
	}
	if (d)
	{
		m_cameraOffset.x += delta * OFFSET_SPEED;
		auto camera = get_node<Camera2D>("Camera2D");
		camera->set_offset(m_cameraOffset);
		UtilityFunctions::print("camera change offset right = ", m_cameraOffset);
	}
	if (f10)
	{
		auto menu = get_node_or_null("/root/Main/Menu");
		if (!menu)
		{
			// make this scene transparent
				set_modulate(Color(1, 1, 1, 0.2f));
				get_node<HUD>("HUD")->set_visible(false);

			// todo: pause all related nodes

			// create menu
			Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/menu.tscn");
			if (ref->can_instantiate())
			{
				auto main = get_node<Main>("/root/Main");
				auto menu = ref->instantiate();
				main->add_child(menu);
			}
		}
		else
		{
			restoreOpacity();

			// clean menu
			menu->get_parent()->remove_child(menu);
			menu->queue_free();
		}
		m_keyPressed = true;
	}
}

void Game::gameOver()
{
	auto menu = get_node_or_null("/root/Main/Menu");
	if (!menu)
	{
		// make this scene transparent
		auto canvas = cast_to<CanvasItem>(this);
		if (canvas)
		{
			canvas->set_modulate(Color(1, 1, 1, 0.2f));
		}

		// todo pause game

		// create menu
		Ref<PackedScene> ref = ResourceLoader::get_singleton()->load("res://scenes/menu.tscn");
		if (ref->can_instantiate())
		{
			menu = ref->instantiate();
			get_parent()->add_child(menu);
			Title* title = cast_to<Menu>(menu)->get_node<Title>("VBoxContainer/title");
			title->set_text("[font_size=30] [wave amp=5 connected=0] GAME OVER ");
			// todo create game over scene
		}
	}
}

void Game::restoreOpacity()
{
	if (auto canvas = cast_to<CanvasItem>(this); canvas)
	{
		canvas->set_modulate(Color(1, 1, 1, 1));
	}
}

void Game::restoreCamera()
{
	auto camera = get_node<Camera2D>("Camera2D");
	camera->set_offset(Vector2(DEFAULT_CAMERA_OFFSET_X, DEFAULT_CAMERA_OFFSET_Y));
	camera->set_zoom(Vector2(DEFAULT_CAMERA_ZOOM_X, DEFAULT_CAMERA_ZOOM_Y));
}
