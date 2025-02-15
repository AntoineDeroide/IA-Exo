#pragma once
#include ".\LightEngine\Entity.h"
#include "SFML/Graphics.hpp"


class Zombie : public Entity {
private:
	int mHp;
	int mDamage;

public:
	Zombie(int b_radius, sf::Color b_color);

	void Walk();
	void TakeDamage(int damage);
	void Attack(Entity* attacked);

	void OnCollision(Entity* collideWith) override;
	void OnUpdate() override;

};
