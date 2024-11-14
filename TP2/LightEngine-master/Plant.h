#pragma once
#include "C:\Users\genes\Documents\GitHub\IA-Exo\TP2\LightEngine-master\LightEngine\Entity.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Projectile;

class Plant : public Entity {
private:
	int mHp;
	
	int mAmmo;
	int mCapacity;
	Projectile* mProjectile;

	float mReloadCooldown;
	float mReloadProgress;

	float mShootCooldown;
	float mShootProgress;

	int mRadius;
	
public:
	Plant(int b_radius, sf::Color b_color);

	void Shoot();
	void Reload();

	void OnUpdate() override;
};