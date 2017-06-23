#include "player_code.hpp"
#include "level_manager.hpp"
#include "game_globals.hpp"
#include "player.hpp"


using namespace Azo;

PlayerCode::PlayerCode(){}

PlayerCode::PlayerCode(engine::GameObject &game_object){
	DEBUG("PlayerCode::PlayerCode method.");
	player = dynamic_cast<Player *>(&game_object);
	this->component_state = engine::State::ENABLED;
	player->state = PlayerState::STANDING;
	FindAnimationController();
}

void PlayerCode::FindAnimationController(){
	this->anim_controller = *(player->GetAnimationController(typeid(engine::AnimationController)));
}

void PlayerCode::UpdateCode(){
	DEBUG("PlayerCode::UpdateCode method.");

	// Player is on ground.
	if(player->y >= global::phase_floor){
		player->y = global::phase_floor;
		player->is_on_ground = true;
	}

	// Player is on left limit of the phase.
	if(player->x <= global::phase_limit_left){
		player->x = global::phase_limit_left;
		player->fictional_position_x = global::phase_limit_left;
	}

	// Player is on right limit of the phase.
	if(player->fictional_position_x >= global::phase_limit_right){
		player->x = engine::Game::instance.sdl_elements.GetWindowWidth() - 75;
		player->fictional_position_x = global::phase_limit_right;
	}

	// Player is on the middle of the canvas.
	if(player->fictional_position_x <= global::phase_limit_to_go_right && player->x >= engine::Game::instance.sdl_elements.GetWindowWidth() / 3){
		player->x = engine::Game::instance.sdl_elements.GetWindowWidth() / 3;
	}

	if(engine::Game::instance.input_manager.KeyState(engine::Button::A)){
		if(player->fictional_position_x >= global::phase_limit_to_go_right || player->fictional_position_x <= engine::Game::instance.sdl_elements.GetWindowWidth() / 3){
			player->x -= global::player_velocity;
		}else{
			// Nothing to do.
		}

		player->fictional_position_x -= global::player_velocity;

		if(player->is_on_ground){
			anim_controller.StopAllAnimations();
			anim_controller.StartAnimation("walking_left");
			player->state = PlayerState::RUNNING;
		}else{
			// Nothing to do.
		}

	}else if(engine::Game::instance.input_manager.KeyState(engine::Button::D)){
		if(player->fictional_position_x >= global::phase_limit_to_go_right || player->fictional_position_x <= engine::Game::instance.sdl_elements.GetWindowWidth() / 3){
			player->x += global::player_velocity;
		}else{
			// Nothing to do.
		}

		player->fictional_position_x += global::player_velocity;

		if(player->is_on_ground){
			anim_controller.StopAllAnimations();
			anim_controller.StartAnimation("walking_right");
			player->state = PlayerState::RUNNING;
		}else{
			// Nothing to do.
		}

	}else{
		if(player->is_on_ground){
			anim_controller.StopAllAnimations();
			anim_controller.StartAnimation("standing");
			player->state = PlayerState::STANDING;
		}else{
			// Nothing to do;
		}
	}

	if(engine::Game::instance.input_manager.KeyState(engine::Button::W)){
		if(player->is_on_ground){
			timer.Step();

			anim_controller.StopAllAnimations();
			anim_controller.StartAnimation("jumping");
			player->is_on_ground = false;
			player->state = PlayerState::JUMPING;
		}else{
			// Nothing to do.
		}

	}

	if(!player->is_on_ground){
		timer.DeltaTime();
		if(timer.GetDeltaTime() <= 500.0f){
			//INFO("Tempo: " << timer.GetDeltaTime());
			player->y -= 11;
		}
	}

	Gravity();
	DEBUG("Posição canvas: " << player->x);
	DEBUG("Posição ficticia: " << player->fictional_position_x);
}

void PlayerCode::Gravity(){
	// Gravity that pulls the player down.
	if(!player->is_on_ground){
		player->y += 6;
	}
}

void PlayerCode::CheckCollisionWithFloor(){
	std::list<std::string>::iterator it;

	for(it = player->collision_list.begin(); it != player->collision_list.end(); ++it){
		auto collision = *it;
		if(collision == "Floor"){
			// CheckMovingRight();
			// CheckMovingLeft();
			player->collision_list.erase(it);
			break;
		}
	}
}

void PlayerCode::CheckCollisionWithWall(){
	std::list<std::string>::iterator it;

	for(it = player->collision_list.begin(); it != player->collision_list.end(); ++it){
		auto collision = *it;
		if(collision == "Wall"){
			player->collision_list.erase(it);
			LevelManager::level_manager.GoToMenu();
			break;
		}
	}
}
