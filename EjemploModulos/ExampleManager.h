#pragma once
#include "Singleton.h"
#include <iostream>

class ExampleManager  : public Singleton<ExampleManager>
{
	friend class Singleton<ExampleManager>;

public:
	void startup()
	{
		std::cout << "Inizializando ExampleManager..." << "\n";
	}
	void shutdown()
	{
		std::cout << "Finalizando ExampleManager..." << "\n";
	}
};

