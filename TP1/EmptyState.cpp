#include "EmptyState.h"

void EmptyState::Start(Gun* gun)
{
    std::cout << "No ammo left...\n";
}

void EmptyState::Update(float deltaTime, Gun* gun)
{
    std::cout << "Empty\n";
}

