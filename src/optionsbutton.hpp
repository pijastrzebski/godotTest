#pragma once

#include "godotcustombutton.hpp"

using namespace godot;

class OptionsButton : public GodotCustomButton
{
	GDCLASS(OptionsButton, GodotCustomButton)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

	void showOptions();
	void closeOptions();

private:
	Node* m_options = nullptr;
};
