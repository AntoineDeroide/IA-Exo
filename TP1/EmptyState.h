#include "State.h"

class EmptyState : public State
{
    void Start() override;
    void Update(float deltaTime) override;
};