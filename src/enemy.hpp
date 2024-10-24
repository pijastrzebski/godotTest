#pragma once

#include "godot_cpp/classes/area2d.hpp"
#include "godot_cpp/classes/character_body2d.hpp"
#include "godot_cpp/classes/path_follow2d.hpp"

using namespace godot;

class Enemy : public CharacterBody2D
{
	GDCLASS(Enemy, CharacterBody2D)

public:
	explicit Enemy();

	void _physics_process(double delta);
	void _ready();

	void setPath(Node* path);
	PathFollow2D* getPathFollow() const;
protected:
	static void _bind_methods();

private:
	void onCollision(Area2D* area);

	Node* m_path = nullptr;

	float m_pathProgress = 0;

};