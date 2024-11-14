#include "State.h"
#include "Plant.h"

void IdleState::Start(Plant* plant)
{
    
}

void IdleState::Update(float deltaTime, Plant* plant)
{
    std::cout << "Idle\n";
}

void ShootingState::Start(Plant* plant)
{

    plant->mAmmo--;

    std::cout << "Bang ! Ammo left : " << plant->mAmmo << std::endl; // Debug + feedback
}

void ShootingState::Update(float deltaTime, Plant* plant)
{
    std::cout << "Shooting\n";

    plant->mShootProgress += deltaTime;
    
    if(plant->mShootProgress >= plant->mShootCooldown)
    {
        std::cout << "Finished shooting !\n";
        plant->mShootProgress = 0;
        if(plant->mAmmo == 0)
            plant->TransitionTo(Plant::stateList::Empty);
    }


}

void ReloadingState::Start(Plant* plant)
{
    std::cout << "Reloading...\n";
}

void ReloadingState::Update(float deltaTime, Plant* plant)
{
    std::cout << "Reloading\n";
    plant->mReloadProgress += deltaTime;
    if((plant->mReloadProgress) >= plant->mReloadCooldown)
    {
        std::cout << "Finished reloading !\n";
        plant->mReloadProgress = 0;
        plant->mAmmo = plant->mCapacity;
        plant->TransitionTo(Plant::stateList::Idle);
    }
}

void EmptyState::Start(Plant* plant)
{
    std::cout << "No ammo left...\n";
}

void EmptyState::Update(float deltaTime, Plant* plant)
{
    std::cout << "Empty\n";
}