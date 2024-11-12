#include "State.h"

class IdleState : public State
{
    void Start() override;
    void Update(float deltaTime) override;
};