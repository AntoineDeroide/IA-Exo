#include "Ball.h"
#include "Player.h"

Player* Ball::IsDetainedBy() {

	return mDetainer;

}

void Ball::Move() {

	SetPosition(GetPosition().x + mDirection.x * mSpeed, GetPosition().y + mDirection.y * mSpeed);

}

void Ball::OnUpdate(){

	std::cout << "mIsDetained : " << mIsDetained << std::endl;
	if (!mIsDetained)
		Move();

}
