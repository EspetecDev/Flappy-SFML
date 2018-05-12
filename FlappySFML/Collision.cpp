#include "Collision.hpp"



namespace Fuet {

	Collision::Collision() {


	}

	bool Collision::CheckSpriteCollision(sf::Sprite s1, sf::Sprite s2) {

		sf::Rect<float> rect1 = s1.getGlobalBounds();
		sf::Rect<float> rect2 = s2.getGlobalBounds();

		if (rect1.intersects(rect2)) return true;
		else return false;
	}

	bool Collision::CheckSpriteCollision(sf::Sprite s1, float scale1, sf::Sprite s2, float scale2) {

		s1.setScale(scale1, scale1);
		s2.setScale(scale2, scale2);

		sf::Rect<float> rect1 = s1.getGlobalBounds();
		sf::Rect<float> rect2 = s2.getGlobalBounds();

		if (rect1.intersects(rect2)) return true;
		else return false;
	}
}