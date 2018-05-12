#pragma once

#include <SFML\Graphics.hpp>

namespace Fuet {

	class Collision {

	public:

		Collision();

		bool CheckSpriteCollision(sf::Sprite s1, sf::Sprite s2);
		bool CheckSpriteCollision(sf::Sprite s1, float scale1, sf::Sprite s2, float scale2);

	private:


	};
}