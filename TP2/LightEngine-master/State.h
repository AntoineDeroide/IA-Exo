﻿#pragma once
#include "iostream"

class Plant;

class State
{
public:
    virtual void Start(Plant* plant) = 0;
    virtual void Update(Plant* plant) = 0;
};

class IdleState : public State
{
    void Start(Plant* plant) override;
    void Update(Plant* plant) override;
};

class ShootingState : public State
{
    void Start(Plant* plant) override;
    void Update(Plant* plant) override;
};

class ReloadingState : public State
{
    void Start(Plant* plant) override;
    void Update(Plant* plant) override;
};

class EmptyState : public State
{
    void Start(Plant* plant) override;
    void Update(Plant* plant) override;
};