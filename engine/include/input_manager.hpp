#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include "sdl2include.h"

#include <string>
#include <list>

namespace engine {

	enum Button {
		W		= SDL_SCANCODE_W,
		A		= SDL_SCANCODE_A,
		S		= SDL_SCANCODE_S,
		D		= SDL_SCANCODE_D,
		ENTER		= SDL_SCANCODE_RETURN,
		SPACE		= SDL_SCANCODE_SPACE,
		BACKSPACE	= SDL_SCANCODE_BACKSPACE
	};

	class InputManager {
		private:
			unsigned int last_event_type;
			std::list<SDL_Event> event_list;
			const Uint8 *keyboard_states;

		public:
			InputManager();

			~InputManager();

			void Update(SDL_Event _event);

			bool KeyDown(Button button);
			bool KeyDownOnce(Button button);

			bool KeyState(Button button);

			void Clear();
	};
}

#endif
