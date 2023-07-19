// EjemploModulos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Singleton.h"
#include "ExampleManager.h"
#include "conio.h"

class MyEntero : public Singleton<MyEntero>
{
    //para poder acceder a los miembros privados de Singleton
    friend class Singleton<MyEntero>;

    public:

        int value;

        void PrintValue() 
        {
            std::cout << value << "\n";
        };
};

int main()
{
    MyEntero::GetInstance().value = 219;
    MyEntero::GetInstance().PrintValue();
    MyEntero::GetInstance().value = 128;
    MyEntero::GetInstance().PrintValue();

    //preparar cosas para el engine
    ExampleManager::GetInstance().startup();

    std::cout << "Hello World!\n";

    int keycode = 0;
    while (keycode != 27) // osea esc
    {
        keycode = _getch();
        std::cout << "keycode= " << keycode << "\n";
        
    }
    std::cout << "user closed the engine\n";
    ExampleManager::GetInstance().shutdown();
}
