#include <iostream>
#include "MenuView.h"
#include "Controller.h"



int main()
{
	srand((uint16_t)time(nullptr));
	Controller controller;
	controller.mainMenu();
}

