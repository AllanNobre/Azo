#include "player_code.hpp"


using namespace Azo;


PlayerCode::PlayerCode(){}

void PlayerCode::SetGameObject(engine::GameObject &game_object){
	this->game_object = &game_object;
	this->component_state = engine::State::ENABLED;
	this->state = PlayerState::RUNNING;
	FindAnimationController();
}

void PlayerCode::FindAnimationController(){
	this->anim_controller = *(game_object->GetComponentByType(typeid(engine::AnimationController)));
}

bool PlayerCode::UpdateCode(){
	if(game_object->state == engine::GameObjectState::COLLIDING){
		ResolveCollision();
	}

	// Catch the User input.
	input_manager.Update();

	// The player should jump (INPUT = 'W').
	if(input_manager.KeyDown(SDL_SCANCODE_W) && this->state == PlayerState::RUNNING){
		timer.Step();
		this->state = PlayerState::JUMPING;
		anim_controller.StartAnimation("jumping");
		anim_controller.StopAnimation("walking_foward");
		anim_controller.StopAnimation("walking_backward");
	}

	if(this->state == PlayerState::JUMPING){
		timer.DeltaTime();
		if(timer.GetDeltaTime() <= 300.0f){
			INFO("Tempo: " << timer.GetDeltaTime());
			game_object->y -= 13;
		}else{
			this->state = PlayerState::FALLING;
		}
	}

	if(this->state == PlayerState::RUNNING){
		anim_controller.StopAnimation("jumping");
		anim_controller.StartAnimation("walking_foward");
	}

	// The player should slide (INPUT = 'S').
	if(input_manager.KeyDown(SDL_SCANCODE_S)){
		game_object->y += 3;
	}

	// Gravity that pulls the player down.
	if(game_object->y <= 230){
		game_object->y += 6;
	}

	// Verify if the player stopped to fall.
	if(game_object->y >= 230){
		this->state = PlayerState::RUNNING;
	}

	// Stop the player almost in the center of the page
	if(game_object->x >= 310){
		game_object->x = 310;
	}

	// Continuous run to right.
	game_object->x += 4;

	return true;
}


void PlayerCode::ResolveCollision(){
	for(auto collision : this->game_object->collision_object_list){
		INFO("GameObject name: " << collision->GetGameObjectName());
	}

	game_object->x = -200;

	// Reseting the default state to a non colliding game object.
	this->game_object->collision_object_list.pop_front();
	this->game_object->state = engine::GameObjectState::NOT_COLLIDING;
}
