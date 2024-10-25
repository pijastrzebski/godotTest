#include "player.hpp"

#include "godot_cpp/classes/canvas_layer.hpp"
#include "godot_cpp/classes/rich_text_label.hpp"
#include "godot_cpp/classes/texture_progress_bar.hpp"

void Player::_process(double delta)
{
}

void Player::_ready()
{
	// set up a new player
	auto hud = get_parent()->get_node<CanvasLayer>("HUD");
	// HP
	auto hpBar = hud->get_node<TextureProgressBar>("main/hpBar/progress");
	hpBar->set_value(m_stats.hp);
	auto hpText = hpBar->get_node<RichTextLabel>("text");
	hpText->set_text(String("[font_size=30][color=white][b]HP ") + String::num(m_stats.hp) + "/" + String::num(m_stats.maxHP));
	// XP
	auto xpBar = hud->get_node<TextureProgressBar>("main/xpBar/progress");
	xpBar->set_value(m_stats.xp);
	auto xpText = xpBar->get_node<RichTextLabel>("text");
	xpText->set_text(String("[font_size=30][color=black][b]XP ") + String::num(m_stats.xp) + "/" + String::num(m_stats.xpToNextLevel));
}

void Player::_bind_methods()
{
}
