#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"

class Projectile : public Entity{
private:
	float mSpeed;

public:
	Projectile();

	void Move();

	void OnCollision(Entity* collideWith) override;
};
