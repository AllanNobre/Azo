#include "level_one.hpp"

using namespace Azo;

LevelOne::LevelOne(){}

LevelOne::LevelOne(std::string name){
	this->scene_name = name;
	SetDependencies();
}

void LevelOne::SetDependencies(){
	CreateGameObjects();
	SetGameObjects();
}

void LevelOne::CreateGameObjects(){
	player = new Player("McCree", 0, 300);
	floor_platform = new Floor("floor", 0, 500);
	wall = new Wall("wall", 530, 450);
	floor_plataform_two = new Floor("floor_1", 1100, 500);
}

void LevelOne::SetGameObjects(){
	INFO("Setting LevelOne GameObjects.");
	this->AddGameObject(*player);
	this->AddGameObject(*floor_platform);
	this->AddGameObject(*wall);
	this->AddGameObject(*floor_plataform_two);
}

void LevelOne::Shutdown(){
	INFO("Destroying LevelOne.");
	DestroyGameObjects();
}

void LevelOne::DestroyGameObjects(){
	INFO("Destroying LevelOne GameObjects.");
	player->Shutdown();
	free(player);
	player = NULL;

	floor_platform->Shutdown();
	free(floor_platform);
	floor_platform = NULL;

	floor_plataform_two->Shutdown();
	free(floor_plataform_two);
	floor_plataform_two = NULL;


	wall->Shutdown();
	free(wall);
	wall = NULL;

	INFO("LevelOne GameObjects Destroyed.");
}

void LevelOne::UpdateCode(){
	for(auto each_game_object : game_object_map){
		auto game_object = each_game_object.second;

		if(game_object->GetClassName() == "Player"){
			if(game_object->x >= engine::Game::instance.sdl_elements.GetWindowWidth() / 3){
				apply_update = true;
			}
			if(apply_update == false){
				game_object->UpdateCode();
			}
		}

		if(apply_update){
			game_object->UpdateCode();
		}
	}
}
