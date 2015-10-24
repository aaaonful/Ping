#pragma once

#include "game_state.h"
#include "entity.h"

class main_game : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	Entity* paddle;

	sf::Font* font;
	sf::Text* title;
};