#pragma once

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

struct GodotRegisterTypes
{
	static void initializeTestLibModule(ModuleInitializationLevel level);
	static void uninitializeTestLibModule(ModuleInitializationLevel level);
};
