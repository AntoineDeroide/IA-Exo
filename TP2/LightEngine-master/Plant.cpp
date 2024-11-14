#include "Plant.h"
#include "../LightEngine-master/LightEngine/Entity.h"
#include "./LightEngine/Scene.h"
#include "Projectile.h"
#include "State.h"

Plant::Plant(int b_radius, sf::Color b_color) : mRadius(b_radius), mHp(100), Entity(b_radius, b_color) {
	SetPosition(300, 0);
	SetTag(0);
}

void Plant::OnUpdate() {

	currentState->Update();

}

bool Plant::TransitionTo(stateList newState)
{
	if (mTransitions[static_cast<int>(mState)][static_cast<int>(newState)] == 0)
		return false;

	mState = newState;
	currentState = mStateArray[static_cast<int>(mState)];
	return true;
}
