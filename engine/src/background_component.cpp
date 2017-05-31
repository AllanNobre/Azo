#include "background_component.hpp"
#include "game.hpp"
#include "game_object.hpp"
#include "sdl.hpp"

using namespace engine;


BackgroundComponent::BackgroundComponent(){}

BackgroundComponent::BackgroundComponent(GameObject & game_object, std::string image_path){
	this->game_object = &game_object;
	this->image_path = image_path;
	this->component_state = State::ENABLED;
}

BackgroundComponent::~BackgroundComponent(){}

bool BackgroundComponent::Init(){
	// Check AssetsManager to see if image is already loaded.
	auto assets_image = Game::instance.GetAssetsManager().LoadImage(image_path);

	image_texture = assets_image->texture;

	return true;
}

bool BackgroundComponent::Shutdown(){
	/* Terminate Texture */
	image_texture = NULL;
	return true;
}

bool BackgroundComponent::Draw(){
	SDL_RenderCopy(
		Game::instance.sdl_elements.GetCanvas(),
		image_texture,
		NULL,
		NULL
		);

	return true;
}
