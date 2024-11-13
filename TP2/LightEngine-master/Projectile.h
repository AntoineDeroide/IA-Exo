#pragma once
#include "./LightEngine/Entity.h"
#include "SFML/Graphics.hpp"

class Projectile : public Entity{
private:
	float mSpeed;

public:
	Projectile();

	void Move();

	void OnCollision(Entity* collideWith) override;

	void OnUpdate() override;
};
