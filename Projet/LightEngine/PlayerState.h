#include "SFML/Graphics.hpp"
#include "Entity.h"
#include <iostream>

class State {
public:
	virtual void Start();
	virtual void Update();
};

// ------------
// ----Idle----
// ------------

class IdleState : public State{
public:
	void Start() override;
	void Update() override;
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