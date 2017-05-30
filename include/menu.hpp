#ifndef MENU_HPP
#define MENU_HPP

#include <string>

#include "scene.hpp"
#include "menu_code.hpp"
#include "background_component.hpp"

namespace Azo {
	class Menu : public engine::Scene {
		private:
			MenuCode menu_code;
		public:
			Menu();
			~Menu();
			Menu(std::string scene_name);
		private:
			void SetMenuDependencies();
	};
}

#endif