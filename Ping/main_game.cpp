#include "main_game.h"
#include "main_menu.h"

void main_game::Initialize(sf::RenderWindow* window)
{
	this->player1 = new paddle_player(0);
	this->player2 = new paddle_player(1);
	this->player1->setPosition(0, window->getSize().y / 2 + this->player1->getGlobalBounds().height / 4);
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2 + this->player2->getGlobalBounds().height / 4);

	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/font.ttf");
	this->score1 = new Score(*font, 64U);
	this->score2 = new Score(*font, 64U);

	this->score2->setPosition(window->getSize().x - this->score2->getGlobalBounds().width, 0);

	this->ballObject = new ball(this->score1, this->score2, this->player1, this->player2);
	this->ballObject->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void main_game::Update(sf::RenderWindow* window)
{
	this->player1->Update();
	this->player2->Update();

	this->score1->Update();
	this->score2->Update();

	this->ballObject->Update(window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.SetState(new main_menu());
	}
}

void main_game::Render(sf::RenderWindow* window)
{
	window->draw(*this->score1);
	window->draw(*this->score2);
	window->draw(*this->player1);
	window->draw(*this->player2);
	window->draw(*this->ballObject);
}

void main_game::Destroy(sf::RenderWindow* window)
{
	delete this->score1;
	delete this->score2;
	delete this->player1;
	delete this->player2;
	delete this->ballObject;
}
