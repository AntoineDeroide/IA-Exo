#pragma once
#include ".\LightEngine\Entity.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Projectile;
class State;

class Plant : public Entity {
public:
	friend class IdleState;
	friend class ShootingState;
	friend class ReloadingState;
	friend class EmptyState;

	enum class stateList
	{
		Idle,
		Shooting,
		Reloading,
		Empty,
    
		StateCount
	};

	static const int STATE_COUNT = (int)stateList::StateCount;

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

	int mTransitions[STATE_COUNT][STATE_COUNT] = {
		//Idle, isShooting, isReloading, Empty
		{0,1,1,0}, //Idle
		{1,0,0,1}, //isShooting
		{1,0,0,0},  //isReloading
		{0,0,1,0},  //Empty
	};
	
public:
	stateList mState;
	State* currentState;
	State* mStateArray[STATE_COUNT];
	
	Plant(int b_radius, sf::Color b_color);

	void OnUpdate() override;

	bool TransitionTo(stateList newState);
};