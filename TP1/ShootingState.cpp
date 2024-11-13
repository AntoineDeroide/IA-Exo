#include "ShootingState.h"

#include "Gun.h"

void ShootingState::Start(Gun* gun)
{

    gun->mAmmo--;

    std::cout << "Bang ! Ammo left : " << gun->mAmmo << std::endl; // Debug + feedback
}

void ShootingState::Update(float deltaTime, Gun* gun)
{
    std::cout << "Shooting\n";

    gun->mShootProgress += deltaTime;
    
    if(gun->mShootProgress >= gun->mShootTime)
    {
        std::cout << "Finished shooting !\n";
        gun->mShootProgress = 0;
        if(gun->mAmmo == 0)
            gun->TransitionTo(Gun::stateList::Empty);
    }


}

