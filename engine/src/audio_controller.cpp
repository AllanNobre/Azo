#include "audio_controller.hpp"

using namespace engine;

void AudioController::Init(){
	for(auto audio_row : audio_map){
		auto audio = audio_row.second;
		audio->Init();
	}
}

void AudioController::Shutdown(){
	for(auto audio_row : audio_map){
		auto audio = audio_row.second;
		INFO("Asking for Shutting Down Audio: " << audio->GetAudioPath());
		audio->Shutdown();
	}
	//audio_map.clear();
}

void AudioController::UpdateCode(){
	for(auto audio_row : audio_map){
		auto audio = audio_row.second;
		if(audio->IsEnabled()){
			audio->UpdateCode();
		}
	}
	DEBUG("All audios codes were update, with size: " << this->audio_map.size());
}

AudioController::AudioController(){
	this->component_state = State::ENABLED;
}

AudioController::AudioController(GameObject &game_object){
	this->game_object = &game_object;
	this->component_state = State::ENABLED;
}

void AudioController::AddAudio(std::string audio_name, AudioComponent &audio){
	audio_map[audio_name] = &audio;
	DEBUG(audio_name << "Added to map with size: " << this->audio_map.size());
}

void AudioController::PlayAudio(std::string audio_name){

	auto audio_to_be_played = audio_map.find(audio_name);

	if(audio_to_be_played != audio_map.end()){
		audio_to_be_played->second->Play(-1, -1);

	}else{
		// Nothing to do.
	}
}

void AudioController::PauseAudio(std::string audio_name){
	auto audio_to_be_played = audio_map.find(audio_name);

	if(audio_to_be_played != audio_map.end()){
		audio_to_be_played->second->Pause(-1);
	}else{
		ERROR("Audio couldn't be found!");
	}
}

void AudioController::StopAudio(std::string audio_name){
	auto audio_to_be_played = audio_map.find(audio_name);

	if(audio_to_be_played != audio_map.end()){
		audio_to_be_played->second->Stop(-1);
	}else{
		ERROR("Audio couldn't be found!");
	}
}

AudioState AudioController::GetAudioState(std::string audio_name){
	auto audio = audio_map.find(audio_name);

	if(audio == audio_map.end()){
		ERROR("Audio doesn't exist");
	}

	return audio->second->audio_state;
}
