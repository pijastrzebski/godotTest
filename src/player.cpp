#include "player.hpp"

#include "game.hpp"
#include "godot_cpp/classes/canvas_layer.hpp"
#include "godot_cpp/classes/rich_text_label.hpp"
#include "godot_cpp/classes/texture_progress_bar.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void Player::_process(double delta)
{
}

void Player::_ready()
{
	// set up a new player
	updateHPBar(m_stats.hp);
	updateXPBar(m_stats.xp);
}

void Player::adjustHP(double hp)
{
	m_stats.hp += hp;

	if (m_stats.hp > m_stats.maxHP)
	{
		m_stats.hp = m_stats.maxHP;
	}
	if (m_stats.hp < 0)
	{
		m_stats.hp = 0;
		UtilityFunctions::print("GAME OVER");
		auto game = cast_to<Game>(get_parent());
		game->gameOver();
	}

	updateHPBar(m_stats.hp);
}

void Player::_bind_methods()
{
}

void Player::updateHPBar(double hp)
{
	auto hud = get_parent()->get_node<CanvasLayer>("HUD");
	// HP
	auto hpBar = hud->get_node<TextureProgressBar>("main/hpBar/progress");
	hpBar->set_value(hp);
	auto hpText = hpBar->get_node<RichTextLabel>("text");
	hpText->set_text(String("[font_size=30][color=white][b]HP ") + String::num(hp) + "/" + String::num(m_stats.maxHP));
}

void Player::updateXPBar(double xp)
{
	auto hud = get_parent()->get_node<CanvasLayer>("HUD");
	auto xpBar = hud->get_node<TextureProgressBar>("main/xpBar/progress");
	xpBar->set_value(m_stats.xp);
	auto xpText = xpBar->get_node<RichTextLabel>("text");
	xpText->set_text(String("[font_size=30][color=black][b]XP ") + String::num(m_stats.xp) + "/" + String::num(m_stats.xpToNextLevel));
}
