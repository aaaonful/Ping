#include "main_game.h"
#include "main_menu.h"

void main_game::Initialize(sf::RenderWindow* window)
{
	this->paddle = new Entity();
	this->paddle->Load("paddle1.png");
	
}

void main_game::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.SetState(new main_menu());
	}
}

void main_game::Render(sf::RenderWindow* window)
{
	//drawing an entity to the screen causes the problem
	window->draw(*this->paddle);
}

void main_game::Destroy(sf::RenderWindow* window)
{
	delete paddle;
}
