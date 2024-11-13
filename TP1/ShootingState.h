#pragma once
#include "State.h"
#include <iostream>

class ShootingState : public State
{
    void Start(Gun* gun) override;
    void Update(float deltaTime, Gun* gun) override;
};