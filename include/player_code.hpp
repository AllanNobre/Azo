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

	enum class PlayerState {
		JUMPING,
		FALLING,
		STANDING,
		RUNNING
	};

	class PlayerCode : public engine::CodeComponent {
		private:
			engine::Timer timer;
			engine::AnimationController anim_controller;
			PlayerState state;

			void CheckCollisionWithFloor();
			void CheckCollisionWithWall();
			void RunRight();
			void RunLeft();
			void CheckJump();
			void CheckMovingRight();
			void CheckMovingLeft();
			void Gravity();

		public:
			PlayerCode();
			PlayerCode(engine::GameObject &game_object);
			void UpdateCode();
			void FindAnimationController();
	};

}

#endif
