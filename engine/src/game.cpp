#include "sdl2include.h"
#include "game.hpp"
#include <iostream>
#include <cstdlib>

using namespace engine; // Used to avoid write engine::Game engine::Game::instance;.

Game Game::instance;    // Used to Initialize in fact the static instance of game;

Game::Game(){
	this->need_to_change_scene = false;
	this->current_scene = NULL;
	this->last_scene = NULL;
	this->frame_rate = 60;
}

// Main Game Loop and SDL Initiators.
void Game::Run(){

	// (SDL) Initialize all SDL attributes: Windows, Canvas, SDL_IMAGE, SDL_VIDEO, SDL_AUDIO.
	sdl_elements.InitSDL();

	// (SDL) Create Window and Canvas.
	sdl_elements.CreateWindow();

	// (STATE) Set game state to show that it's running.
	game_state = engine::GameState::PLAY;

	// Calculate how many time will have one frame of the Game (miliseconds).
	frame_time = 1000.0f / frame_rate;


	INFO("Starting Main Loop Game.");
	while(game_state == engine::GameState::PLAY){

		// Get the current time.
		timer.Step();

		if(StartAndStopScenes() == false){
			break;
		}

		// Reading input (events).
		SDL_Event _event;

		// "Search" for a event that will close the Game.
		while(SDL_PollEvent(&_event)){
			switch(_event.type){
				case SDL_QUIT:
					// (STATE) Set game state to show that it'll Die.
					game_state = engine::GameState::EXIT;
					break;
				default:
					// Check for user inputs.
					input_manager.Update(_event);
					break;
			}
		}

		// Clean and Draw the Scene to refreh animations and objects.
		SDL_RenderClear(sdl_elements.GetCanvas());

		INFO(current_scene->GetSceneName() << " Draw.");

		current_scene->Draw();
		SDL_RenderPresent(sdl_elements.GetCanvas());

		DEBUG("Updating current scene: " << current_scene->GetSceneName() << " code.");

		current_scene->UpdateCode();

		//INFO("Clearing user input from InputManager.");
		input_manager.Clear();

		//INFO("Calculating elapsed time from the start of this frame until now");
		timer.DeltaTime();

		/* If the time that has passed until now was faster than the frame's time, is needed wait
		   the time necessary to complete a frame's time.*/
		if(frame_time > timer.GetDeltaTime()){
			SDL_Delay(frame_time - timer.GetDeltaTime());
		}

		timer.DeltaTime();
	}

	INFO("Finishing Main Loop.");

	INFO("Shutting down SDL.");
	sdl_elements.TerminateSDL();
}


// Used to add a Scene to map that have all Game's Scenes.
bool Game::AddScene(Scene &scene){
	auto scene_name = scene.GetSceneName();

	INFO("Adding scene: " << scene_name);

	if(scene_map.find(scene_name) != scene_map.end()){
		ERROR("Scene already exists!");
		return false;
	}else{
		// Nothing to Do.
	}

	scene_map[scene_name] = &scene;
	DEBUG("Scene Map size after putting this scene is " << scene_map.size());

	return true;
}


// Perform the necessary checks and prepare the structure to switch Scenes.
void Game::ChangeScene(std::string scene_name){
	INFO("Changing Scenes: " << scene_name);

	if(scene_map.find(scene_name) == scene_map.end()){
		ERROR("Scene not found!");
	}else{
		// Nothing to Do.
	}

	last_scene = current_scene;
	current_scene = scene_map[scene_name];
	need_to_change_scene = true;

	if(last_scene != NULL){
		INFO("Last Scene: " << last_scene->GetSceneName());
	}else{
		INFO("Last Scene é NULL.");
	}

	INFO("Current Scene: " << current_scene->GetSceneName());
}


// Perform scene switching effectively.
bool Game::StartAndStopScenes(){
	if(need_to_change_scene){
		if(current_scene == NULL){
			ERROR("No scenes to run!");
			return false;
		}else{

			current_scene->Init();

			if(last_scene != NULL){
				INFO("Shuting down scene: " << last_scene->GetSceneName());
				scene_map.erase(last_scene->GetSceneName());
				last_scene->Shutdown();
				free(last_scene);
				last_scene = NULL;
			}else{
				// Nothing to Do.
			}

			DEBUG(current_scene->GetSceneName() << " Initialized.");

			need_to_change_scene = false;
		}
	}

	return true;
}


/* Transfer the game_name, window_width and window_height to SDL instace through its method "SetSDLAttributes"
   and set Game's frame_rate. */
void Game::SetAttributes(std::string game_name, int window_width, int window_height, int frame_rate){
	sdl_elements.SetSDLAttributes(game_name, window_width, window_height);
	this->frame_rate = frame_rate;
}
