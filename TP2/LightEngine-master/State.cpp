#include "State.h"
#include "Plant.h"
//------------
//----IDLE----
//------------

void IdleState::Start(Plant* plant)
{
    
}

void IdleState::Update(float deltaTime, Plant* plant)
{
    std::cout << "Idle\n";
}

//----------------
//----SHOOTING----
//----------------

void ShootingState::Start(Plant* plant)
{
    if (plant->TransitionTo(Plant::stateList::Shooting))
        plant->mState = Plant::stateList::Shooting;
    
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

//-----------------
//----RELOADING----
//-----------------

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

//-------------
//----EMPTY----
//-------------

void EmptyState::Start(Plant* plant)
{
    std::cout << "No ammo left...\n";
}

void EmptyState::Update(float deltaTime, Plant* plant)
{
    std::cout << "Empty\n";
    
    // Recharger automatiquement
    if (plant->TransitionTo(Plant::stateList::Reloading))
        plant->mState = Plant::stateList::Reloading;
}