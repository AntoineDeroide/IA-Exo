#pragma once
#include "State.h"

class EmptyState : public State
{
    void Start(Gun* gun) override;
    void Update(float deltaTime, Gun* gun) override;
};