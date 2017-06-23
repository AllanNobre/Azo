#ifndef GAME_GLOBALS_HPP
#define GAME_GLOBALS_HPP

#include <string>

namespace global {
	const std::string game_name = "Oza-Forasteiro";
	const int window_width = 800;   // Pixels.
	const int window_height = 600;  // Pixels
	const int frame_rate = 60;      // Frames per Second (FPS)
	const std::string player_scene = "player_scene";
	const int player_velocity = 6;
	const int phase_limit_right = 2830;
	const int phase_limit_left = 0;
	const int phase_limit_to_go_right = 2000;
	const int phase_floor = 390;
}

#endif
