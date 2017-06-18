#include "moving_image_component.hpp"
#include "game.hpp"

using namespace engine;

MovingImageComponent::MovingImageComponent(){}

MovingImageComponent::MovingImageComponent(GameObject &game_object, std::string image_path, double resize){
	this->game_object = &game_object;
	this->image_path = image_path;
	this->resize = resize;
}

void MovingImageComponent::Init(){
	// Check AssetsManager to see if image is already loaded.
	auto assets_image = Game::instance.GetAssetsManager().LoadImage(image_path);

	image_texture = assets_image->texture;

	component_width = assets_image->width;
	component_height = assets_image->height;

	game_object->game_object_width = (int)(component_width * resize);

	game_object->game_object_height = (int)(component_height * resize);

	canvasQuad = {game_object->x,
		      game_object->y,
		      (int)(component_width * resize),
		      (int)(component_height * resize)};

	renderQuad = {0, 0, component_width, component_height};
}

void MovingImageComponent::Draw(){
	UpdateQuad();
	UpdateGameObjectMeasures();

	int successful_draw = SDL_RenderCopy(
		Game::instance.sdl_elements.GetCanvas(),
		image_texture,
		&renderQuad,
		&canvasQuad
		);

	if(successful_draw < 0){
		ERROR("Unable to draw.");
	}
}

void MovingImageComponent::UpdateQuad(){
	canvasQuad = {
		BackgroundComponent::game_object->x,
		BackgroundComponent::game_object->y,
		(int)(component_width * resize),
		(int)(component_height * resize)
	};
}

void MovingImageComponent::UpdateGameObjectMeasures(){
	// Before drawing, set the GameObject sizes so we can calculate collision.

	game_object->left = game_object->x;
	game_object->right = game_object->x + game_object->game_object_width;
	game_object->top = game_object->y;
	game_object->bottom = game_object->y + game_object->game_object_height;

}
