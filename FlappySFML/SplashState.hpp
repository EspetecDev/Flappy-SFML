#pragma once

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"

namespace Fuet {

	class SplashState : public State{

	public:

		SplashState(GameDataRef data);
		
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:

		GameDataRef _data;
		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;
	};
}