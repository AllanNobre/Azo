#include "game_object.hpp"
#include "game.hpp"
#include "code_component.hpp"

using namespace engine;


GameObject::GameObject(){}

GameObject::GameObject(std::string game_object_name, int x, int y){
	this->game_object_name = game_object_name;

	this->x = x;
	this->y = y;

	this->top = 0;
	this->bottom = 0;
	this->left = 0;
	this->right = 0;
};

// Used to add a component to Game Object's "component_map" (map with the component and its type).
bool engine::GameObject::AddComponent(engine::Component &component){
	std::pair <std::type_index, Component *> component_pair(typeid(component), &component);

	component_map.insert(component_pair);

	return true;
}

/* Find the desired component by type and get (returns) the found component, which, in this case,
   can only be an AnimationController.
   OBS: This method is used be possible to communicate between components. */
AnimationController* GameObject::GetAnimationController(std::type_index component_type){
	auto component_to_be_found = component_map.find(component_type);

	if(component_to_be_found != component_map.end()){
		return dynamic_cast <AnimationController * > (component_to_be_found->second);
	}else{
		ERROR("Animation Controller couldn't be found!");
	}
}

AudioController* GameObject::GetAudioController(std::type_index component_type){
	auto component_to_be_found = component_map.find(component_type);

	if(component_to_be_found != component_map.end()){
		return dynamic_cast <AudioController * > (component_to_be_found->second);
	}else{
		ERROR("Audio Controller couldn't be found!");
	}
}

// Call all Init methods of the components of the Game Object.
void GameObject::Init(){
	DEBUG("Initializing game_object: " << this->game_object_name);
	for(auto each_pair : component_map){
		auto component = each_pair.second;
		if(component->IsEnabled()){
			component->Init();
		}
	}
}

// Call all Draw and Update methods of the components of the Game Object.
void GameObject::Draw(){
	DEBUG("Components Map size before Drawing: " << component_map.size());
	INFO("Drawing components of game_object: " << this->game_object_name);
	for(auto each_pair : component_map){
		auto component = each_pair.second;
		if(component->IsEnabled()){
			component->Draw();
		}
	}
	DEBUG("Components Drew for game object: " << this->game_object_name);
}


void GameObject::UpdateCode(){
	for(auto each_pair : component_map){
		auto component = each_pair.second;
		if(component->IsEnabled()){
			component->UpdateCode();
		}
	}
}


// Call all Shutdowns methods of the components of the Game Object.
void engine::GameObject::Shutdown(){
	for(auto each_pair : component_map){
		auto component = each_pair.second;
		component->Shutdown();
	}
}
