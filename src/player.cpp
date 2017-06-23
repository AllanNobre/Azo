#include "player.hpp"

using namespace Azo;

Player::Player(){}

Player::Player(std::string name, int x, int y){
	this->game_object_name = name;

	this->x = x;
	this->y = y;

	this->fictional_position_x = x;
	this->fictional_position_y = y;

	CreateComponents();
}

void Player::CreateComponents(){
	DEBUG("Creating Player Components.");

	DEBUG("Creating Animation Controller.");
	m_anim_controller = new engine::AnimationController();


	DEBUG("Creating Walking Right Animation Controller.");
	GenWalkingRightAnimation();

	m_walking_right = new engine::Animation(*this,
						"sprites/CowboyRunRight.png",
						1000.0f,
						m_walking_right_animation_sprites,
						0,
						22);

	m_walking_right->DisableComponent();


	DEBUG("Adding walking right animation to animation controller.");
	m_anim_controller->AddAnimation("walking_right", *m_walking_right);


	DEBUG("Creating Walking Left Animation Controller.");
	GenWalkingLeftAnimation();

	m_walking_left = new engine::Animation(*this,
					       "sprites/CowboyRunLeft.png",
					       1000.0f,
					       m_walking_left_animation_sprites,
					       0,
					       23);

	m_walking_left->DisableComponent();


	DEBUG("Adding walking left animation to animation controller.");
	m_anim_controller->AddAnimation("walking_left", *m_walking_left);


	DEBUG("Creating Jumping Animation Controller.");
	GenJumpingAnimation();

	m_jumping = new engine::Animation(*this,
					  "sprites/CowboyJump.png",
					  1000.0f,
					  m_jumping_animation_sprites,
					  0,
					  7);

	m_jumping->DisableComponent();

	DEBUG("Adding jumping animation to animation controller");
	m_anim_controller->AddAnimation("jumping", *m_jumping);


	DEBUG("Creating Standing Animation Controller.");
	m_standing = new engine::Animation(*this,
					   "sprites/CowboyJump.png",
					   10000.0f,
					   m_jumping_animation_sprites,
					   0,
					   0);


	DEBUG("Adding standing animation to animation controller");
	m_anim_controller->AddAnimation("standing", *m_standing);


	DEBUG("Adding animation controller to Player.");
	this->AddComponent(*m_anim_controller);


	DEBUG("Creating Player Code.");
	m_player_code = new PlayerCode(*this);

	DEBUG("Adding player code to Player.");
	this->AddComponent(*m_player_code);
}

void Player::GenWalkingRightAnimation(){
	DEBUG("Generating player walking right animation.");
	for(int i = 0; i < 23; i++){
		m_walking_right_animation_sprites.push_back(new engine::Sprite());
	}

	m_walking_right_animation_sprites[0]->sprite_x = 2;
	m_walking_right_animation_sprites[0]->sprite_y = 34;
	m_walking_right_animation_sprites[0]->sprite_width = 67 - 2;
	m_walking_right_animation_sprites[0]->sprite_height = 139 - 34;

	m_walking_right_animation_sprites[1]->sprite_x = 71;
	m_walking_right_animation_sprites[1]->sprite_y = 34;
	m_walking_right_animation_sprites[1]->sprite_width = 136 - 71;
	m_walking_right_animation_sprites[1]->sprite_height = 139 - 34;

	m_walking_right_animation_sprites[2]->sprite_x = 137;
	m_walking_right_animation_sprites[2]->sprite_y = 34;
	m_walking_right_animation_sprites[2]->sprite_width = 202 - 137;
	m_walking_right_animation_sprites[2]->sprite_height = 139 - 34;

	m_walking_right_animation_sprites[3]->sprite_x = 203;
	m_walking_right_animation_sprites[3]->sprite_y = 20;
	m_walking_right_animation_sprites[3]->sprite_width = 273 - 203;
	m_walking_right_animation_sprites[3]->sprite_height = 139 - 20;

	m_walking_right_animation_sprites[4]->sprite_x = 274;
	m_walking_right_animation_sprites[4]->sprite_y = 20;
	m_walking_right_animation_sprites[4]->sprite_width = 344 - 274;
	m_walking_right_animation_sprites[4]->sprite_height = 139 - 20;

	m_walking_right_animation_sprites[5]->sprite_x = 345;
	m_walking_right_animation_sprites[5]->sprite_y = 20;
	m_walking_right_animation_sprites[5]->sprite_width = 415 - 345;
	m_walking_right_animation_sprites[5]->sprite_height = 139 - 20;

	m_walking_right_animation_sprites[6]->sprite_x = 416;
	m_walking_right_animation_sprites[6]->sprite_y = 26;
	m_walking_right_animation_sprites[6]->sprite_width = 501 - 416;
	m_walking_right_animation_sprites[6]->sprite_height = 139 - 26;

	m_walking_right_animation_sprites[7]->sprite_x = 502;
	m_walking_right_animation_sprites[7]->sprite_y = 26;
	m_walking_right_animation_sprites[7]->sprite_width = 585 - 502;
	m_walking_right_animation_sprites[7]->sprite_height = 139 - 26;

	m_walking_right_animation_sprites[8]->sprite_x = 587;
	m_walking_right_animation_sprites[8]->sprite_y = 26;
	m_walking_right_animation_sprites[8]->sprite_width = 672 - 587;
	m_walking_right_animation_sprites[8]->sprite_height = 139 - 26;

	m_walking_right_animation_sprites[9]->sprite_x = 673;
	m_walking_right_animation_sprites[9]->sprite_y = 26;
	m_walking_right_animation_sprites[9]->sprite_width = 744 - 673;
	m_walking_right_animation_sprites[9]->sprite_height = 139 - 26;

	m_walking_right_animation_sprites[10]->sprite_x = 745;
	m_walking_right_animation_sprites[10]->sprite_y = 26;
	m_walking_right_animation_sprites[10]->sprite_width = 816 - 745;
	m_walking_right_animation_sprites[10]->sprite_height = 139 - 26;

	m_walking_right_animation_sprites[11]->sprite_x = 889;
	m_walking_right_animation_sprites[11]->sprite_y = 26;
	m_walking_right_animation_sprites[11]->sprite_width = 960 - 889;
	m_walking_right_animation_sprites[11]->sprite_height = 139 - 26;

	m_walking_right_animation_sprites[12]->sprite_x = 961;
	m_walking_right_animation_sprites[12]->sprite_y = 34;
	m_walking_right_animation_sprites[12]->sprite_width = 1029 - 961;
	m_walking_right_animation_sprites[12]->sprite_height = 139 - 34;

	m_walking_right_animation_sprites[13]->sprite_x = 1031;
	m_walking_right_animation_sprites[13]->sprite_y = 34;
	m_walking_right_animation_sprites[13]->sprite_width = 1099 - 1031;
	m_walking_right_animation_sprites[13]->sprite_height = 139 - 34;

	m_walking_right_animation_sprites[14]->sprite_x = 1100;
	m_walking_right_animation_sprites[14]->sprite_y = 20;
	m_walking_right_animation_sprites[14]->sprite_width = 1165 - 1100;
	m_walking_right_animation_sprites[14]->sprite_height = 139 - 20;

	m_walking_right_animation_sprites[15]->sprite_x = 1166;
	m_walking_right_animation_sprites[15]->sprite_y = 20;
	m_walking_right_animation_sprites[15]->sprite_width = 1231 - 1166;
	m_walking_right_animation_sprites[15]->sprite_height = 139 - 20;

	m_walking_right_animation_sprites[16]->sprite_x = 1232;
	m_walking_right_animation_sprites[16]->sprite_y = 20;
	m_walking_right_animation_sprites[16]->sprite_width = 1296 - 1232;
	m_walking_right_animation_sprites[16]->sprite_height = 139 - 20;

	m_walking_right_animation_sprites[17]->sprite_x = 1297;
	m_walking_right_animation_sprites[17]->sprite_y = 26;
	m_walking_right_animation_sprites[17]->sprite_width = 1382 - 1297;
	m_walking_right_animation_sprites[17]->sprite_height = 139 - 26;

	m_walking_right_animation_sprites[18]->sprite_x = 1383;
	m_walking_right_animation_sprites[18]->sprite_y = 26;
	m_walking_right_animation_sprites[18]->sprite_width = 1468 - 1383;
	m_walking_right_animation_sprites[18]->sprite_height = 139 - 26;

	m_walking_right_animation_sprites[19]->sprite_x = 1469;
	m_walking_right_animation_sprites[19]->sprite_y = 26;
	m_walking_right_animation_sprites[19]->sprite_width = 1554 - 1469;
	m_walking_right_animation_sprites[19]->sprite_height = 139 - 26;


	m_walking_right_animation_sprites[20]->sprite_x = 1555;
	m_walking_right_animation_sprites[20]->sprite_y = 29;
	m_walking_right_animation_sprites[20]->sprite_width = 1629 - 1555;
	m_walking_right_animation_sprites[20]->sprite_height = 139 - 29;

	m_walking_right_animation_sprites[21]->sprite_x = 1631;
	m_walking_right_animation_sprites[21]->sprite_y = 29;
	m_walking_right_animation_sprites[21]->sprite_width = 1707 - 1631;
	m_walking_right_animation_sprites[21]->sprite_height = 139 - 29;

	m_walking_right_animation_sprites[22]->sprite_x = 1709;
	m_walking_right_animation_sprites[22]->sprite_y = 29;
	m_walking_right_animation_sprites[22]->sprite_width = 1784 - 1709;
	m_walking_right_animation_sprites[22]->sprite_height = 139 - 29;
}

void Player::GenWalkingLeftAnimation(){
	DEBUG("Generating player walking left animation.");
	for(int i = 0; i < 24; i++){
		m_walking_left_animation_sprites.push_back(new engine::Sprite());
	}

	m_walking_left_animation_sprites[0]->sprite_x = 1732;
	m_walking_left_animation_sprites[0]->sprite_y = 34;
	m_walking_left_animation_sprites[0]->sprite_width = 1798 - 1732;
	m_walking_left_animation_sprites[0]->sprite_height = 139 - 34;

	m_walking_left_animation_sprites[1]->sprite_x = 1663;
	m_walking_left_animation_sprites[1]->sprite_y = 34;
	m_walking_left_animation_sprites[1]->sprite_width = 1729 - 1663;
	m_walking_left_animation_sprites[1]->sprite_height = 139 - 34;

	m_walking_left_animation_sprites[2]->sprite_x = 1597;
	m_walking_left_animation_sprites[2]->sprite_y = 34;
	m_walking_left_animation_sprites[2]->sprite_width = 1663 - 1597;
	m_walking_left_animation_sprites[2]->sprite_height = 139 - 34;

	m_walking_left_animation_sprites[3]->sprite_x = 1527;
	m_walking_left_animation_sprites[3]->sprite_y = 20;
	m_walking_left_animation_sprites[3]->sprite_width = 1597 - 1527;
	m_walking_left_animation_sprites[3]->sprite_height = 139 - 20;

	m_walking_left_animation_sprites[4]->sprite_x = 1455;
	m_walking_left_animation_sprites[4]->sprite_y = 20;
	m_walking_left_animation_sprites[4]->sprite_width = 1527 - 1455;
	m_walking_left_animation_sprites[4]->sprite_height = 139 - 20;

	m_walking_left_animation_sprites[5]->sprite_x = 1384;
	m_walking_left_animation_sprites[5]->sprite_y = 20;
	m_walking_left_animation_sprites[5]->sprite_width = 1455 - 1384;
	m_walking_left_animation_sprites[5]->sprite_height = 139 - 20;

	m_walking_left_animation_sprites[6]->sprite_x = 1298;
	m_walking_left_animation_sprites[6]->sprite_y = 26;
	m_walking_left_animation_sprites[6]->sprite_width = 1384 - 1298;
	m_walking_left_animation_sprites[6]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[7]->sprite_x = 1213;
	m_walking_left_animation_sprites[7]->sprite_y = 26;
	m_walking_left_animation_sprites[7]->sprite_width = 1298 - 1213;
	m_walking_left_animation_sprites[7]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[8]->sprite_x = 1127;
	m_walking_left_animation_sprites[8]->sprite_y = 26;
	m_walking_left_animation_sprites[8]->sprite_width = 1213 - 1127;
	m_walking_left_animation_sprites[8]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[9]->sprite_x = 1055;
	m_walking_left_animation_sprites[9]->sprite_y = 26;
	m_walking_left_animation_sprites[9]->sprite_width = 1127 - 1055;
	m_walking_left_animation_sprites[9]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[10]->sprite_x = 983;
	m_walking_left_animation_sprites[10]->sprite_y = 26;
	m_walking_left_animation_sprites[10]->sprite_width = 1055 - 983;
	m_walking_left_animation_sprites[10]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[11]->sprite_x = 911;
	m_walking_left_animation_sprites[11]->sprite_y = 26;
	m_walking_left_animation_sprites[11]->sprite_width = 983 - 911;
	m_walking_left_animation_sprites[11]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[12]->sprite_x = 839;
	m_walking_left_animation_sprites[12]->sprite_y = 26;
	m_walking_left_animation_sprites[12]->sprite_width = 911 - 839;
	m_walking_left_animation_sprites[12]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[13]->sprite_x = 770;
	m_walking_left_animation_sprites[13]->sprite_y = 34;
	m_walking_left_animation_sprites[13]->sprite_width = 839 - 770;
	m_walking_left_animation_sprites[13]->sprite_height = 139 - 34;

	m_walking_left_animation_sprites[14]->sprite_x = 700;
	m_walking_left_animation_sprites[14]->sprite_y = 34;
	m_walking_left_animation_sprites[14]->sprite_width = 769 - 700;
	m_walking_left_animation_sprites[14]->sprite_height = 139 - 34;

	m_walking_left_animation_sprites[15]->sprite_x = 634;
	m_walking_left_animation_sprites[15]->sprite_y = 20;
	m_walking_left_animation_sprites[15]->sprite_width = 698 - 634;
	m_walking_left_animation_sprites[15]->sprite_height = 139 - 20;

	m_walking_left_animation_sprites[16]->sprite_x = 568;
	m_walking_left_animation_sprites[16]->sprite_y = 20;
	m_walking_left_animation_sprites[16]->sprite_width = 632 - 568;
	m_walking_left_animation_sprites[16]->sprite_height = 139 - 20;

	m_walking_left_animation_sprites[17]->sprite_x = 503;
	m_walking_left_animation_sprites[17]->sprite_y = 20;
	m_walking_left_animation_sprites[17]->sprite_width = 566 - 503;
	m_walking_left_animation_sprites[17]->sprite_height = 139 - 20;

	m_walking_left_animation_sprites[18]->sprite_x = 417;
	m_walking_left_animation_sprites[18]->sprite_y = 26;
	m_walking_left_animation_sprites[18]->sprite_width = 503 - 417;
	m_walking_left_animation_sprites[18]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[19]->sprite_x = 331;
	m_walking_left_animation_sprites[19]->sprite_y = 26;
	m_walking_left_animation_sprites[19]->sprite_width = 417 - 331;
	m_walking_left_animation_sprites[19]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[20]->sprite_x = 245;
	m_walking_left_animation_sprites[20]->sprite_y = 26;
	m_walking_left_animation_sprites[20]->sprite_width = 331 - 245;
	m_walking_left_animation_sprites[20]->sprite_height = 139 - 26;

	m_walking_left_animation_sprites[21]->sprite_x = 170;
	m_walking_left_animation_sprites[21]->sprite_y = 29;
	m_walking_left_animation_sprites[21]->sprite_width = 245 - 170;
	m_walking_left_animation_sprites[21]->sprite_height = 139 - 29;

	m_walking_left_animation_sprites[22]->sprite_x = 92;
	m_walking_left_animation_sprites[22]->sprite_y = 29;
	m_walking_left_animation_sprites[22]->sprite_width = 169 - 92;
	m_walking_left_animation_sprites[22]->sprite_height = 139 - 29;

	m_walking_left_animation_sprites[23]->sprite_x = 15;
	m_walking_left_animation_sprites[23]->sprite_y = 29;
	m_walking_left_animation_sprites[23]->sprite_width = 92 - 15;
	m_walking_left_animation_sprites[23]->sprite_height = 139 - 29;
}

void Player::GenJumpingAnimation(){
	DEBUG("Generating Player Jumping Animation.");

	for(int i = 0; i < 8; i++){
		m_jumping_animation_sprites.push_back(new engine::Sprite());
	}

	m_jumping_animation_sprites[0]->sprite_x = 20;
	m_jumping_animation_sprites[0]->sprite_y = 22;
	m_jumping_animation_sprites[0]->sprite_width = 94 - 20;
	m_jumping_animation_sprites[0]->sprite_height = 127 - 22;

	m_jumping_animation_sprites[1]->sprite_x = 14;
	m_jumping_animation_sprites[1]->sprite_y = 168;
	m_jumping_animation_sprites[1]->sprite_width = 97 - 24;
	m_jumping_animation_sprites[1]->sprite_height = 267 - 168;

	m_jumping_animation_sprites[2]->sprite_x = 8;
	m_jumping_animation_sprites[2]->sprite_y = 282;
	m_jumping_animation_sprites[2]->sprite_width = 103 - 8;
	m_jumping_animation_sprites[2]->sprite_height = 398 - 282;

	m_jumping_animation_sprites[3]->sprite_x = 8;
	m_jumping_animation_sprites[3]->sprite_y = 422;
	m_jumping_animation_sprites[3]->sprite_width = 103 - 8;
	m_jumping_animation_sprites[3]->sprite_height = 538 - 422;

	m_jumping_animation_sprites[4]->sprite_x = 16;
	m_jumping_animation_sprites[4]->sprite_y = 562;
	m_jumping_animation_sprites[4]->sprite_width = 97 - 16;
	m_jumping_animation_sprites[4]->sprite_height = 678 - 562;

	m_jumping_animation_sprites[5]->sprite_x = 16;
	m_jumping_animation_sprites[5]->sprite_y = 702;
	m_jumping_animation_sprites[5]->sprite_width = 97 - 16;
	m_jumping_animation_sprites[5]->sprite_height = 818 - 702;

	m_jumping_animation_sprites[6]->sprite_x = 16;
	m_jumping_animation_sprites[6]->sprite_y = 842;
	m_jumping_animation_sprites[6]->sprite_width = 99 - 16;
	m_jumping_animation_sprites[6]->sprite_height = 958 - 842;

	m_jumping_animation_sprites[7]->sprite_x = 14;
	m_jumping_animation_sprites[7]->sprite_y = 997;
	m_jumping_animation_sprites[7]->sprite_width = 83 - 20;
	m_jumping_animation_sprites[7]->sprite_height = 1107 - 997;
}

void Player::Shutdown(){
	INFO("Destroying Player Components.");
	ASSERT(m_walking_right != NULL, "Walking Animation can't be NULL while shutting down.");
	ASSERT(m_jumping != NULL, "Jumping Animation can't be NULL while shutting down.");
	ASSERT(m_anim_controller != NULL, "Animation Controller can't be NULL while shutting down.");
	ASSERT(m_player_code != NULL, "Player Code can't be NULL while shutting down.");

	for(int i = 0; i < 23; i++){
		free(m_walking_right_animation_sprites[i]);
		m_walking_right_animation_sprites[i] = NULL;
	}

	for(int i = 0; i < 8; i++){
		free(m_jumping_animation_sprites[i]);
		m_jumping_animation_sprites[i] = NULL;
	}

	m_walking_right->Shutdown();
	free(m_walking_right);
	m_walking_right = NULL;

	m_jumping->Shutdown();
	free(m_jumping);
	m_jumping = NULL;

	m_standing->Shutdown();
	free(m_standing);
	m_standing = NULL;

	m_player_code->Shutdown();
	free(m_player_code);
	m_player_code = NULL;

	free(m_anim_controller);
	m_anim_controller = NULL;
}
