#pragma once

#include "godot_cpp/classes/button.hpp"

using namespace godot;

class StartButton : public Button
{
	GDCLASS(StartButton, Button)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void start();
	void closeGame();

private:
};
