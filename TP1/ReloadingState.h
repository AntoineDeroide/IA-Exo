#include "State.h"

class ReloadingState : public State
{
    void Start() override;
    void Update(float deltaTime) override;
};