#pragma once

#include "godot_cpp/classes/button.hpp"

using namespace godot;

class OptionsButton : public Button
{
	GDCLASS(OptionsButton, Button)

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
