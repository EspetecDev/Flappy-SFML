#include <sstream>
#include <iostream>
#include "GameState.hpp"
#include "Definitions.hpp"
#include "GameOverState.hpp"

namespace Fuet {

	GameState::GameState(GameDataRef data) : _data(data) {
		std::cout << "[GameState::GameState] Game state" << std::endl;

	}

	void GameState::Init() {

		if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH)) {
			std::cout << "[GameState::Init] Hit sound could not be loaded" << std::endl;
		}
		if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH)) {
			std::cout << "[GameState::Init] Wing sound could not be loaded" << std::endl;
		}
		if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH)) {
			std::cout << "[GameState::Init] Point sound could not be loaded" << std::endl;
		}

		_hitSound.setBuffer(_hitSoundBuffer);
		_wingSound.setBuffer(_wingSoundBuffer);
		_pointSound.setBuffer(_pointSoundBuffer);

		_data->assets.LoadTexture("GameStateBackground", GAME_STATE_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("PipeUp", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("PipeDown", PIPE_DOWN_FILEPATH);
		_data->assets.LoadTexture("ScoringPipe", PIPE_SCORING_FILEPATH);
		_data->assets.LoadTexture("Land", LAND_FILEPATH);
		_data->assets.LoadTexture("BirdFrame1", BIRD_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("BirdFrame2", BIRD_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("BirdFrame3", BIRD_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("BirdFrame4", BIRD_FRAME_4_FILEPATH);
		_data->assets.LoadFont("FlappyFont", FLAPPY_FONT_FILEPATH);
		
		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		flash = new Flash(_data);
		hud = new HUD(_data);

		_score = 0;
		hud->UpdateScore(_score);

		_background.setTexture(this->_data->assets.GetTexture("GameStateBackground"));
		_gameState = GameStates::eReady;

	}

	void GameState::HandleInput() {

		sf::Event event;

		while (_data->window.pollEvent(event)) {

			if (sf::Event::Closed == event.type)
				_data->window.close();

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
				if (GameStates::eGameOver != _gameState) {
					
					_gameState = GameStates::ePlaying;
					bird->Tap();
					_wingSound.play();
				}
			}

		}
	}

	void GameState::Update(float dt) {

		if (GameStates::eGameOver != _gameState) {
			
			bird->Animate(dt);
			land->MoveLand(dt);
		}

		if(GameStates::ePlaying == _gameState){

			pipe->MovePipes(dt);

			if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
				pipe->RandomisePipeOffset();

				pipe->SpawnIvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				pipe->SpawnScoringPipe();

				_clock.restart();
			}

			
			bird->Update(dt);
			

			// Ground collision
			std::vector<sf::Sprite> landSprites = land->GetSprites();
			
			for (int i = 0; i < landSprites.size(); i++) {
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, landSprites.at(i), 1.0f)) {
					
					_gameState = GameStates::eGameOver;
					
					_clock.restart();

					_hitSound.play();
				}
			}

			// Pipe collision
			std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

			for (int i = 0; i < pipeSprites.size(); i++) {
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f)) {

					_gameState = GameStates::eGameOver;

					_clock.restart();

					_hitSound.play();
				}
			}


			if (GameStates::ePlaying == _gameState) {
				
				// Scoring pipe collision
				std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprites();
				//std::cout << "Sp: " << scoringSprites.size() << std::endl;

				for (int i = 0; i < scoringSprites.size(); i++) {
					if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, scoringSprites.at(i), 1.0f)) {

						_score++;

						hud->UpdateScore(_score);

						scoringSprites.erase(scoringSprites.begin() + i);

						_pointSound.play();
					}
				}
			}
			

		}
		
		// GameOver flash
		if (GameStates::eGameOver == _gameState) {
				
			flash->Show(dt);
			
			if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
				_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
		}
	}

	void GameState::Draw(float dt) {

		_data->window.clear();

		_data->window.draw(_background);
		pipe->DrawPipes();
		land->DrawLand();
		bird->Draw();
		flash->Draw();
		hud->Draw();

		_data->window.display();
	}
}


