#include "PlayerState.h"

// ------------
// ----Idle----
// ------------

void IdleState::Start() {
	std::cout << "Idle" << std::endl;
}

void IdleState::Update() {

}

// -----------
// ----Run----
// -----------

void RunState::Start() {
	std::cout << "Run" << std::endl;
}

void RunState::Update() {

}

// --------------
// ----Sprint----
// --------------

void SprintState::Start() {
	std::cout << "Sprint" << std::endl;
}

void SprintState::Update() {

}

// --------------
// ----Follow----
// --------------

void FollowState::Start() {
	std::cout << "Follow" << std::endl;
}

void FollowState::Update() {

}

// -----------------
// ----Intercept----
// -----------------

void InterceptState::Start() {
	std::cout << "Intercept" << std::endl;
}

void InterceptState::Update() {

}

// ------------
// ----Give----
// ------------

void GiveState::Start() {
	std::cout << "Give" << std::endl;
}

void GiveState::Update() {

}

// ------------
// ----Mark----
// ------------

void MarkState::Start() {
	std::cout << "Mark" << std::endl;
}

void MarkState::Update() {

}