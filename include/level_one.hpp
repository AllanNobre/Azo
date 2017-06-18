#ifndef LEVEL_ONE_HPP
#define LEVEL_ONE_HPP

#include "scene.hpp"
#include "floor.hpp"
#include "wall.hpp"
#include "player.hpp"

#include <string>

namespace Azo {
	class LevelOne : public engine::Scene {
		private:
			Player *player;
			Floor *floor_platform;
			Floor *floor_plataform_one;
			Wall *wall;
		public:
			bool apply_update = false;
			LevelOne();
			LevelOne(std::string name);
			void UpdateCode();
		private:
			void SetDependencies();
			void CreateGameObjects();
			void SetGameObjects();
			void Shutdown();
			void DestroyGameObjects();
	};
}

#endif
