#include <sstream>
#include <iostream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "Definitions.hpp"

namespace Fuet {

	MainMenuState::MainMenuState(GameDataRef data) : _data(data) {


	}

	void MainMenuState::Init() {

		_data->assets.LoadTexture("MainMenuBackground", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("GameTitle", GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("PlayButton", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("MainMenuBackground"));
		_title.setTexture(this->_data->assets.GetTexture("GameTitle"));
		_playButton.setTexture(this->_data->assets.GetTexture("PlayButton"));

		_title.setPosition((SCREEN_WIDTH / 2) - _title.getGlobalBounds().width / 2,
							_title.getGlobalBounds().height / 2);

		_playButton.setPosition((SCREEN_WIDTH / 2) - _playButton.getGlobalBounds().width / 2,
								(SCREEN_HEIGHT / 2) - _playButton.getGlobalBounds().height / 2);
	}

	void MainMenuState::HandleInput() {

		sf::Event event;

		while (_data->window.pollEvent(event)) {

			if (sf::Event::Closed == event.type)
				_data->window.close();

			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
				std::cout << "[MainMenuState::HandleInput] Go to Play state" << std::endl;
				_data->machine.AddState(StateRef(new GameState(this->_data)));
			}

		}
	}

	void MainMenuState::Update(float dt) {

		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {

			
		}
	}

	void MainMenuState::Draw(float dt) {

		_data->window.clear();
		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);
		_data->window.display();
	}
}

