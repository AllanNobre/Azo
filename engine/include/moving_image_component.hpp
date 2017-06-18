#ifndef MOVING_IMAGE_COMPONENT_HPP
#define MOVING_IMAGE_COMPONENT_HPP

#include "background_component.hpp"
#include <string>

namespace engine {
	class MovingImageComponent : public BackgroundComponent {
		private:
			double resize = 1.0;
		protected:
			SDL_Rect canvasQuad;
		public:
			MovingImageComponent();
			MovingImageComponent(GameObject &game_object, std::string image_path, double resize);
		public:
			void Init();
			void Draw();
			void UpdateQuad();
			void UpdateGameObjectMeasures();

	};
}

#endif
