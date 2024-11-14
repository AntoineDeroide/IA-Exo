#pragma once
#include "./LightEngine/Entity.h"
#include "SFML/Graphics.hpp"

class Projectile : public Entity{
private:
	float mSpeed;

public:
	Projectile(int b_radius, sf::Color b_color);

	void Move();

	void OnCollision(Entity* collideWith) override;

	void OnUpdate() override;
};
