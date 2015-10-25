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
		if (!this->texture->loadFromFile("Graphics/sprites/" + filename))
		{
			printf("error loading texture");
		}
		this->setTexture(*this->texture);
	}

	virtual void Update()
	{
		this->move(this->velocity);
	}

	bool CheckCollision(Entity* entity)
	{
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}

	~Entity()
	{
		delete this->texture;
	}

private:
	sf::Texture* texture;

protected:
	sf::Vector2f velocity;
};