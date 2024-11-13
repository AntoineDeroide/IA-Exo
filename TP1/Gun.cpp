#include "Gun.h"
#include "IdleState.h"
#include "ShootingState.h"
#include "ReloadingState.h"
#include "EmptyState.h"

#include <ostream>
#include <iostream>

Gun::Gun(int bAmmo, int bCapacity, float bReloadTime, float bShootTime) :
        mAmmo(bAmmo), mCapacity(bCapacity), mReloadTime(bReloadTime),
        mShootTime(bShootTime), mReloadProgress(0), mShootProgress(0),
        isShooting(false), isReloading(false)
{
    mStateArray[0] = new IdleState();
    mStateArray[1] = new ShootingState();
    mStateArray[2] = new ReloadingState();
    mStateArray[3] = new EmptyState();

    mState = stateList::Idle;
    int mStateIndex = 0;
}

// void Gun::Update(float dT)
// {
//     std::cout << mState << std::endl;
//     
//     if(mState == Shooting)
//     {
//         mShootProgress += dT;
//         
//         if(mShootProgress >= mShootTime)
//         {
//             std::cout << "Finished shooting !\n";
//             mShootProgress = 0;
//             if(mAmmo == 0)
//                 if(TransitionTo(Empty) == false)
//                     return;
//             mState = Idle;
//         }
//     }
//     else if (mState == Reloading)
//     {
//         mReloadProgress += dT;
//         if((mReloadProgress) >= mReloadTime)
//         {
//             std::cout << "Finished reloading !\n";
//             mReloadProgress = 0;
//             mAmmo = mCapacity;
//             mState = Idle;
//         }
//     }
// }
//
// void Gun::Shoot()
// {
//     if(TransitionTo(Shooting) == false)
//         return;
//
//     mAmmo--;
//     std::cout << "Bang ! Ammo left : " << mAmmo << std::endl; // Debug + feedback
//     mState = Shooting;
// }
//
// void Gun::Reload()
// {
//     if(TransitionTo(State::Reloading) == false)
//         return;
//     
//     std::cout << "Reloading...\n";
// }

bool Gun::TransitionTo(stateList newState)
{
    if (mTransitions[static_cast<int>(mState)][static_cast<int>(newState)] == 0)
        return false;

    mState = newState;
    currentState = mStateArray[static_cast<int>(mState)];
    return true;
}
