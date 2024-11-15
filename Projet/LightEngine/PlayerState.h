#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Action.h"
#include "Condition.h"

#include <iostream>

class Player;

// ------------
// ----Idle----
// ------------

class IdleState : public Action<Player>{
public:
	void Start(Player* player) override;
	void Update(Player* player) override;
	void End(Player* player) override;
};

// ---------------
// ----HasBall----
// ---------------

class HasBallCondition : public Condition<Player> {

};

// -------------------
// ----TeamHasBall----
// -------------------

class TeamHasBallCondition : public Condition<Player> {

};

// ------------------------
// ----EnemyTeamHasBall----
// ------------------------

class EnemyTeamHasBallCondition : public Condition<Player> {

};


// -----------
// ----Run----
// -----------

class RunState : public State {
public:
	void Start() override;
	void Update() override;
};

// --------------
// ----Sprint----
// --------------

class SprintState : public State {
public:
	void Start() override;
	void Update() override;
};

// --------------
// ----Follow----
// --------------

class FollowState : public State {
public:
	void Start() override;
	void Update() override;
};

// -----------------
// ----Intercept----
// -----------------

class InterceptState : public State {
public:
	void Start() override;
	void Update() override;
};

// ------------
// ----Give----
// ------------

class GiveState : public State {
public:
	void Start() override;
	void Update() override;
};

// ------------
// ----Mark----
// ------------

class MarkState : public State {
public:
	void Start() override;
	void Update() override;
};