#pragma once

#include <memory>
#include <string>
#include <SFML\Graphics.hpp>
#include "Definitions.hpp"
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Fuet {

	struct GameData {

		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game {
		
	public:
		
		Game(int width, int height, std::string title);

	private:

		// FrameRate
		const float dt = 1.0f / FRAMERATE;
		sf::Clock _clock;
		
		GameDataRef _data = std::make_shared<GameData>();

		void Run();

	};
}

