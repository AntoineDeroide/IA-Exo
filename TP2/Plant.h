#pragma once
#include "Entity.h"
#include "Projectile.h"
#include "SFML/Graphics.hpp"
#include <iostream>


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
	
public:
	Plant(int b_radius, sf::Color b_color);

	void Shoot();
	void Reload();

	void OnUpdate() override;
};