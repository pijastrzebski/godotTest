#pragma once

#include "godot_cpp/classes/rich_text_label.hpp"

using namespace godot;

class Title : public RichTextLabel
{
	GDCLASS(Title, RichTextLabel)

public:
	void _process(double delta) override;
	void _ready() override;

protected:
	static void _bind_methods();

};
