#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "game_object.hpp"
#include "player_code.hpp"
#include "sprite.hpp"

#include <vector>
#include <string>

namespace Azo {

	enum class PlayerState {
		JUMPING,
		FALLING,
		STANDING,
		RUNNING
	};

	class Player : public engine::GameObject {
		private:
			engine::AnimationController * m_anim_controller;
			engine::Animation *m_walking_right;
			engine::Animation *m_walking_left;
			engine::Animation *m_jumping;
			engine::Animation *m_standing;

			std::vector<engine::Sprite *> m_walking_right_animation_sprites;
			std::vector<engine::Sprite *> m_walking_left_animation_sprites;
			std::vector<engine::Sprite *> m_jumping_animation_sprites;
			std::vector<engine::Sprite *> m_standing_animation_sprites;

			PlayerCode *m_player_code;

		public:
			PlayerState state;
			bool is_on_ground = true;
			int fictional_position_x;
			int fictional_position_y;

		private:
			void CreateComponents();
			void GenWalkingRightAnimation();
			void GenWalkingLeftAnimation();
			void GenJumpingAnimation();
			void GenStandingAnimation();
			inline std::string GetClassName(){
				return "Player";
			}

		public:
			Player();
			Player(std::string name, int x, int y);
			void Shutdown();
	};
}

#endif
