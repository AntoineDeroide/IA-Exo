#pragma once
#include "Entity.h"
#include "StateMachine.h"

class State;

class Player : public Entity {

	StateMachine<Player> mStateMachine;

	friend class State;
	enum playerState {
		Idle,
		HasBall,
		TeamHasBall,
		EnemyTeamHasBall,

		//Run, // Course : vitesse de base ?
		//Sprint, // Sprint : boost de vitesse quand le joueur reçoit la balle
		//Follow, // Follow et Intercept similaires ?
		//Intercept, // Follow et Intercept similaires ?
		//Pickup,
		//Give, // remplacer par "Pass" ?
		//Mark,

		stateCount
	};

	static const int STATE_COUNT = static_cast<int>(stateCount);

private:
	// var
	//bool mHasBall;
	float mSpeed;

	// Speed boost
	float mSpeedBoost;
	float mBoostDuration;
	float mBoostProgress;

	// Invincibilité
	float mInvincibilityDuration;
	float mInvincibilityProgress;

	// Délai entre passes
	float mPassDelayDuration;
	float mPassDelayProgress;

	playerState mState;
	State* mCurrentState;

public:

	Player(int b_radius, sf::Color b_color);

	int GetNearestPlayer();
	int GetDistanceWith(Player* player);

	bool TransitionTo(playerState newState);

};
