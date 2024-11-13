#include "ReloadingState.h"

#include "Gun.h"

void ReloadingState::Start(Gun* gun)
{
    std::cout << "Reloading...\n";
}

void ReloadingState::Update(float deltaTime, Gun* gun)
{
    std::cout << "Reloading\n";
    gun->mReloadProgress += deltaTime;
    if((gun->mReloadProgress) >= gun->mReloadTime)
    {
        std::cout << "Finished reloading !\n";
        gun->mReloadProgress = 0;
        gun->mAmmo = gun->mCapacity;
        gun->TransitionTo(Gun::stateList::Idle);
    }
}