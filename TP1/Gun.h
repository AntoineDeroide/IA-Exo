#include <Windows.h>

class Gun
{
public:
    enum State
    {
        Idle,
        Shooting,
        Reloading,
        Empty,
        
        StateCount
    };

    static const int STATE_COUNT = (int)State::StateCount;

private:
    int mAmmo;
    int mCapacity;
    
    bool isShooting; 
    bool isReloading;

    float mReloadTime;
    float mShootTime;
    float mReloadProgress;
    float mShootProgress;
    
    State mState = State::Idle;

    int mTransitions[STATE_COUNT][STATE_COUNT] = {
        //Idle, isShooting, isReloading, Empty
        {0,1,1,0}, //Idle
        {1,0,0,1}, //isShooting
        {1,0,0,0},  //isReloading
        {0,0,1,0},  //Empty

    };

public:
    Gun(int, int, float, float);
    
    bool SetState(State to);
    void Update(float dT);
    void Shoot();
    void Reload();

    bool TransitionTo(State newState);
};
