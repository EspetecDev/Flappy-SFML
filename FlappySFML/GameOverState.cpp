#include <sstream>
#include <iostream>
#include <fstream>
#include "GameOverState.hpp"
#include "Definitions.hpp"
#include "GameState.hpp"

namespace Fuet {

	GameOverState::GameOverState(GameDataRef data, int score) : _data(data) ,_score(score){
		std::cout << "[GameOverState::GameOverState] Game state" << std::endl;

	}

	void GameOverState::Init() {

		std::ifstream readFile;
		readFile.open(HIGHEST_SCORE_PATH, std::ios::app);

		if (readFile.is_open()) {
			while (!readFile.eof()) {
				readFile >> _highScore;
			}
		}
		else {
			std::cout << "[GameOverState::Init] readFile could not open" << std::endl;
		}

		readFile.close();

		std::ofstream writeFile(HIGHEST_SCORE_PATH);

		if (writeFile.is_open()) {
			if (_score > _highScore) {
				_highScore = _score;
			}

			writeFile << _highScore;
		}
		else {
			std::cout << "[GameOverState::Init] writeFile could not open" << std::endl;
		}

		writeFile.close();

		_data->assets.LoadTexture("GameOverStateBackground", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("GameOverStateTitle", GAME_OVER_TITLE_FILEPATH);
		_data->assets.LoadTexture("GameOverStateBody", GAME_OVER_BODY_FILEPATH);
		_data->assets.LoadTexture("BronzeMedal", BRONZE_MEDAL_FILEPATH);
		_data->assets.LoadTexture("SilverMedal", SILVER_MEDAL_FILEPATH);
		_data->assets.LoadTexture("GoldMedal", GOLD_MEDAL_FILEPATH);
		_data->assets.LoadTexture("PlatinumMedal", PLATINUM_MEDAL_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("GameOverStateBackground"));
		_gameOverTitle.setTexture(this->_data->assets.GetTexture("GameOverStateTitle"));
		_gameOverContainer.setTexture(this->_data->assets.GetTexture("GameOverStateBody"));
		_retryButton.setTexture(this->_data->assets.GetTexture("PlayButton"));

		_gameOverContainer.setPosition(_data->window.getSize().x / 2 - (_gameOverContainer.getGlobalBounds().width / 2),
										(_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2));

		_gameOverTitle.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2),
			_gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2));
		
		_retryButton.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2),
									_gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height +
										_retryButton.getLocalBounds().height * 0.2);

		_scoreText.setFont(_data->assets.GetFont("FlappyFont"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);

		_highScoreText.setFont(_data->assets.GetFont("FlappyFont"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(56);
		_highScoreText.setFillColor(sf::Color::White);
		_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
		_highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78);
		
		if (_score >= PLATINUM_MEDAL_SCORE) {
			_medal.setTexture(_data->assets.GetTexture("PlatinumMedal"));
		}
		else if (_score >= GOLD_MEDAL_SCORE) {
			_medal.setTexture(_data->assets.GetTexture("GoldMedal"));
		}
		else if (_score >= SILVER_MEDAL_SCORE) {
			_medal.setTexture(_data->assets.GetTexture("SilverMedal"));
		}
		else {
			_medal.setTexture(_data->assets.GetTexture("BronzeMedal"));
		}

		_medal.setPosition(175, 465);
	}

	void GameOverState::HandleInput() {

		sf::Event event;

		while (_data->window.pollEvent(event)) {

			if (sf::Event::Closed == event.type)
				_data->window.close();

			if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)) {
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt) {


	}

	void GameOverState::Draw(float dt) {

		_data->window.clear();
		_data->window.draw(_background);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_gameOverTitle);
		_data->window.draw(_retryButton);
		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);
		_data->window.draw(_medal);
		_data->window.display();
	}
}

