#pragma once

#include "Scene.h"
class Plant;
class Projectile;
class Zombie;

class PvZScene : public Scene
{
	Plant* pPlant1;
	Plant* pPlant2;
	Plant* pPlant3;

	Projectile* pProjectile1;
	Projectile* pProjectile2;
	Projectile* pProjectile3;
	Projectile* pProjectile4;
	Projectile* pProjectile5;
	Projectile* pProjectile6;

	Zombie* pZombie1;
	Zombie* pZombie2;
	Zombie* pZombie3;

	Plant* pEntitySelected;

private:
	void TrySetSelectedEntity(Plant* pEntity, int x, int y);

public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};


