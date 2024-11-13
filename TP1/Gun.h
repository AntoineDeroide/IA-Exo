#pragma once
#include <Windows.h>

class State;

class Gun
{
public:
    
    friend class IdleState;
    friend class ShootingState;
    friend class ReloadingState;
    friend class EmptyState;
    
    enum class stateList
    {
        Idle,
        Shooting,
        Reloading,
        Empty,
        
        StateCount
    };
    
    static const int STATE_COUNT = (int)stateList::StateCount;

private:
    int mAmmo;
    int mCapacity;
    
    bool isShooting; 
    bool isReloading;

    float mReloadTime;
    float mShootTime;
    float mReloadProgress;
    float mShootProgress;

    

    int mTransitions[STATE_COUNT][STATE_COUNT] = {
        //Idle, isShooting, isReloading, Empty
        {0,1,1,0}, //Idle
        {1,0,0,1}, //isShooting
        {1,0,0,0},  //isReloading
        {0,0,1,0},  //Empty

    };

public:
    stateList mState;
    State* currentState;
    State* mStateArray[STATE_COUNT];

    Gun(int, int, float, float);
    
    // void Update(float dT);
    // void Shoot();
    // void Reload();

    bool TransitionTo(stateList newState);
};
