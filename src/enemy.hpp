#pragma once

#include "godot_cpp/classes/area2d.hpp"
#include "godot_cpp/classes/path_follow2d.hpp"
#include "godot_cpp/classes/rigid_body2d.hpp"

using namespace godot;

class Enemy : public RigidBody2D
{
	GDCLASS(Enemy, RigidBody2D)

public:
	void _physics_process(double delta);
	void _ready();

	void setPath(Node* path);
protected:
	static void _bind_methods();

private:
	void onCollision(Area2D* area);
	PathFollow2D* getPathFollow() const;

	Node* m_path = nullptr;

	float m_pathProgress = 0;

};
