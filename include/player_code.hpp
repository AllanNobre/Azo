#ifndef PLAYER_CODE_HPP
#define PLAYER_CODE_HPP

#include <typeinfo>
#include <typeindex>

#include "code_component.hpp"
#include "animation_controller.hpp"
#include "timer.hpp"
#include "floor.hpp"
#include "wall.hpp"


namespace Azo {
	class Player;

	class PlayerCode : public engine::CodeComponent {
		private:
			Player *player;
			engine::Timer timer;
			engine::AnimationController anim_controller;

			void CheckCollisionWithFloor();
			void CheckCollisionWithWall();
			void Gravity();

		public:
			PlayerCode();
			PlayerCode(engine::GameObject &game_object);
			void UpdateCode();
			void FindAnimationController();
	};

}

#endif
