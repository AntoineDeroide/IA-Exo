#pragma once
#include "Entity.h"
#include <iostream>

class Player;

class Ball : public Entity {
public:
	friend class Player;
	Player* IsDetainedBy(void);
	void Move();
	void OnUpdate() override;

private:
	bool mIsDetained;
	float mSpeed;
	sf::Vector2f mDirection;
	Player* mDetainer;

	
};
