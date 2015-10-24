#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:
	Entity()
	{
		this->texture = new sf::Texture();
	}

	void Load(std::string filename)
	{
		this->texture->loadFromFile("Graphics/sprites/" + filename);
		this->setTexture(*this->texture);
	}

	~Entity()
	{
		delete this->texture;
	}

private:
	sf::Texture* texture;
};