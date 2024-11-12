#include "State.h"
#include "Gun.h"
#include <iostream>

class ShootingState : public State
{
    void Start() override;
    void Update(float deltaTime) override;
};