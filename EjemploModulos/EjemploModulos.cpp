// EjemploModulos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Singleton.h"

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

    std::cout << "Hello World!\n";
}
