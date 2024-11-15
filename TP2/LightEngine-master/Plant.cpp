#include "Plant.h"
#include "../LightEngine-master/LightEngine/Entity.h"
#include "./LightEngine/Scene.h"
#include "Projectile.h"
#include "State.h"

Plant::Plant(int b_radius, sf::Color b_color) : mRadius(b_radius), mHp(100), Entity(b_radius, b_color) {
	SetPosition(300, 0);
	SetTag(0);
	mStateArray[0] = new IdleState();
	mStateArray[1] = new ShootingState();
	mStateArray[2] = new ReloadingState();
	mStateArray[3] = new EmptyState();

	mCurrentState = mStateArray[0];
}

void Plant::OnUpdate() {

	mCurrentState->Update(this);

}

bool Plant::TransitionTo(stateList newState)
{
	if (mTransitions[static_cast<int>(mState)][static_cast<int>(newState)] == 0)
		return false;

	mState = newState;
	mCurrentState = mStateArray[static_cast<int>(mState)];
	return true;
}
