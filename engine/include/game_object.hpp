#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <map>

#include "animation.hpp"
#include "sdl2include.h"
#include "component.hpp"
#include "image_component.hpp"
#include "animation_controller.hpp"


namespace engine {

	class GameObject {
		public:
			int x, y;               // Game Object positions in canvas.
			int width, height;      // Game Object size in canvas.

		protected:
			std::string game_object_name;                           // Game Object name.
			std::map<std::type_index, Component *> component_list;  /* Map (List) that keep all Game Object's Components. */

		public:
			GameObject();

			GameObject(std::string game_object_name);

			// Used to add a component to Game Object's "component_list" (map with the component and its type).
			bool AddComponent(Component &component);

			/* Find the desired component by type and get (returns) the found component, which, in this case,
			   can only be an AnimationController.
			   OBS: This method is used be possible to communicate between components. */
			AnimationController* GetComponentByType(std::type_index component_type);

			// Used to get (returns) the name of the Game Object.
			inline std::string GetGameObjectName(){
				return game_object_name;
			};

			// Call all Init methods of the components of the Game Object.
			virtual bool Init();

			// Call all Draw and Update methods of the components of the Game Object.
			virtual bool Draw();

			// Call all Shutdowns methods of the components of the Game Object.
			virtual bool Shutdown();
	};

}

#endif
