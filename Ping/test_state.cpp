#include "test_state.h"
#include <iostream>

void test_state::Initialize(sf::RenderWindow* window)
{
	std::cout << "inited\n";
	this->paused = false;
}

void test_state::Update(sf::RenderWindow* window)
{
	if (paused)
	{
		//normal game here
	}
	else
	{
		//paused game here
	}
}

void test_state::Render(sf::RenderWindow* window)
{

}

void test_state::Destroy(sf::RenderWindow* window)
{
	std::cout << "destroyed \n";
}