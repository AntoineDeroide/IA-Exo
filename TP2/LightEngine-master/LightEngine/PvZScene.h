#pragma once

#include "Scene.h"
class Plant;
class Projectile;
class Zombie;

class PvZScene : public Scene
{
	sf::FloatRect lane1;
	sf::FloatRect lane2;
	sf::FloatRect lane3;

	Plant* pPlant1;
	Plant* pPlant2;
	Plant* pPlant3;

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


