#include "AssetManager.hpp"

namespace Fuet {
	
	void AssetManager::LoadTexture(std::string name, std::string fileName) {
		sf::Texture tex;

		if (tex.loadFromFile(fileName)) {
			this->_textures[name] = tex;
		}
		else {
			std::cout << "[AssetManager::LoadTexture] Unable to load texture " << name << "from file." << std::endl;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name) {
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName) {
		sf::Font font;

		if (font.loadFromFile(fileName)) {
			this->_fonts[name] = font;
		}
		else {
			std::cout << "[AssetManager::LoadFont] Unable to load font " << name << "from file." << std::endl;
		}
	}

	sf::Font &AssetManager::GetFont(std::string name) {
		return this->_fonts.at(name);
	}

}

