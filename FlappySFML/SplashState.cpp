#include <sstream>
#include <iostream>
#include "SplashState.hpp"
#include "Definitions.hpp"

namespace Fuet {
	
	SplashState::SplashState(GameDataRef data) : _data(data) {

		
	}

	void SplashState::Init() {

		_data->assets.LoadTexture("SplashStateBackground", SPLASH_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("SplashStateBackground"));
	}

	void SplashState::HandleInput() {

		sf::Event event;

		while (_data->window.pollEvent(event)) {
			
			if (sf::Event::Closed == event.type) 
				_data->window.close();
			
		}
	}

	void SplashState::Update(float dt) {

		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {

			std::cout << "[SplashState::Update] Go to Main Menu" << std::endl;
			_data->machine.AddState(StateRef(new MainMenuState(this->_data)));
		}
	}

	void SplashState::Draw(float dt) {

		_data->window.clear();
		_data->window.draw(_background);
		_data->window.display();
	}
}

