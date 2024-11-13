#pragma once
#include "iostream"

class Gun;

class State
{
public:
    virtual void Start(Gun* gun) = 0;
    virtual void Update(float deltaTime, Gun* gun) = 0;
};