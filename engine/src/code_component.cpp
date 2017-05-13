#include "code_component.hpp"


using namespace engine;

CodeComponent::CodeComponent(){}

CodeComponent::CodeComponent(GameObject &game_object){
	this->game_object = &game_object;
}

bool CodeComponent::Init(){
	return true;
}

bool CodeComponent::Shutdown(){
	return true;
}

bool CodeComponent::UpdateCode(){
	return true;
}