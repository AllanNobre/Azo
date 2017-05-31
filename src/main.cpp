#include "game.hpp"
#include "game_globals.hpp"
#include "code_component.hpp"
#include "player.hpp"
#include "menu.hpp"
#include "menu_code.hpp"
#include "floor.hpp"

using namespace Azo;


int main(int, char**) {
	// Get the Primary Data for create the game and transfer to SDL do this.
	engine::Game::instance.SetAttributes(
		global::game_name,
		global::window_width,
		global::window_height,
		global::frame_rate);


	Menu menu_scene("menu_scene");
	// menu_scene.AddGameObject(play_button_menu);
	// menu_scene.AddGameObject(menu_game_object);

	engine::Game::instance.AddScene(menu_scene);

	// Creating a game object player, Setting Animations to Animation Controller and Setting specific codes.
	Player player("McCree", 0, 300);
	Floor floor_platform("floor", 0, 500);

	// Creating Scenes.
	engine::Scene player_scene(global::player_scene);

	// Adding game objects to respectives Scenes.
	player_scene.AddGameObject(player);
	player_scene.AddGameObject(floor_platform);

	// Adding Scenes to game.
	engine::Game::instance.AddScene(player_scene);

	// Starting game execution.
	engine::Game::instance.Run();

	return 0;
}
