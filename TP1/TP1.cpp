#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <iostream>
#include "Gun.h"
#include "State.h"


void HandleInput(Gun& gun, char input)
{
    if(input == 'r')
    {
        gun.currentState->Start(&gun);
    }
    else if(input == 's')
    {
        gun.Shoot();
    }
}



int main(int argc, char* argv[])
{
    Gun gun(2, 2, 2, 2.5);
    
    bool isRunning = true;
    float deltaTime = 16.66f;
    
    while(isRunning)
    {
        //int start = clock();

        if (_kbhit()) 
        {
            char key = _getch();

            HandleInput(gun, key);
            gun.Update(deltaTime);
            
            std::cout << "Touche pressee : " << key << std::endl;
            if (key == 'q') 
            {
                isRunning = false;
            }

            Sleep(deltaTime);
        }
        
        //int end = clock();
        //deltaTime = end - start;
    }
    return 0;
}
