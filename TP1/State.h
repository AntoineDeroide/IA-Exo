#include "Gun.h"
class State
{
public:
    Gun gun;
    virtual void Start() = 0;
    virtual void Update(float deltaTime) = 0;
};