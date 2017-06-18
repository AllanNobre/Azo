#include "player_code.hpp"
#include "level_manager.hpp"


using namespace Azo;

PlayerCode::PlayerCode(){}

PlayerCode::PlayerCode(engine::GameObject &game_object){
	DEBUG("PlayerCode::PlayerCode method.");
	this->game_object = &game_object;
	this->component_state = engine::State::ENABLED;
	this->state = PlayerState::STANDING;
	FindAnimationController();
}

void PlayerCode::FindAnimationController(){
	this->anim_controller = *(game_object->GetAnimationController(typeid(engine::AnimationController)));
}

void PlayerCode::UpdateCode(){
	DEBUG("PlayerCode::UpdateCode method.");

	if(game_object->y <= 370){
		game_object->y = 370;
	}

	if(engine::Game::instance.input_manager.KeyDown(engine::Button::A)){
		game_object->x -= 8;
		anim_controller.StopAllAnimations();
		anim_controller.StartAnimation("walking_left");
		this->state = PlayerState::RUNNING;
	}else if(engine::Game::instance.input_manager.KeyDown(engine::Button::D)){
		game_object->x += 8;
		anim_controller.StopAllAnimations();
		anim_controller.StartAnimation("walking_right");
		this->state = PlayerState::RUNNING;
	}else{
		this->state = PlayerState::STANDING;
	}

	if(this->state == PlayerState::STANDING){
		anim_controller.StopAllAnimations();
		anim_controller.StartAnimation("standing");
	}

	// if(engine::Game::instance.input_manager.KeyDown(engine::Button::W)){
	//      game_object->x += 5;
	//      anim_controller.StopAllAnimations();
	//      anim_controller.StartAnimation("walking_right");
	// }

	Gravity();
}

void PlayerCode::CheckJump(){
	if(engine::Game::instance.input_manager.KeyDown(engine::Button::W) && this->state != PlayerState::RUNNING){
		DEBUG("Player Jumped.");
		timer.Step();
		this->state = PlayerState::JUMPING;
		anim_controller.StopAnimation("standing");
		anim_controller.StartAnimation("jumping");
	}

	if(this->state == PlayerState::JUMPING){
		timer.DeltaTime();
		if(timer.GetDeltaTime() <= 400.0f){
			//INFO("Tempo: " << timer.GetDeltaTime());
			game_object->y -= 15;
		}else{
			this->state = PlayerState::FALLING;
		}
	}

	if(this->state == PlayerState::RUNNING){
		anim_controller.StopAnimation("jumping");
		anim_controller.StartAnimation("standing");
	}

}

void PlayerCode::CheckMovingRight(){
	// The player should move right (INPUT = 'D').
	if(engine::Game::instance.input_manager.KeyDown(engine::Button::D)){
		RunRight();
	}
}

void PlayerCode::CheckMovingLeft(){
	// The player should move right (INPUT = 'A').
	if(engine::Game::instance.input_manager.KeyDown(engine::Button::A)){
		RunLeft();
	}
}

void PlayerCode::RunRight(){
	// Continuous run to right.
	game_object->x += 5;
}

void PlayerCode::RunLeft(){
	// Continuous run to right.
	game_object->x -= 5;
}

void PlayerCode::Gravity(){
	// Gravity that pulls the player down.
	if(this->state == PlayerState::FALLING || this->state == PlayerState::JUMPING){
		game_object->y += 6;
	}
}


void PlayerCode::CheckCollisionWithFloor(){
	std::list<std::string>::iterator it;

	for(it = game_object->collision_list.begin(); it != game_object->collision_list.end(); ++it){
		auto collision = *it;
		if(collision == "Floor"){
			CheckMovingRight();
			CheckMovingLeft();
			game_object->collision_list.erase(it);
			break;
		}
	}
}

void PlayerCode::CheckCollisionWithWall(){
	std::list<std::string>::iterator it;

	for(it = game_object->collision_list.begin(); it != game_object->collision_list.end(); ++it){
		auto collision = *it;
		if(collision == "Wall"){
			game_object->collision_list.erase(it);
			LevelManager::level_manager.GoToMenu();
			break;
		}
	}
}
