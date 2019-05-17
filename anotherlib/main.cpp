#include <bits/stdc++.h>
#include "LibraryContext.h"
#include "LibraryUserInterface.h"
#include <chrono>
#include <conio.h>
using namespace MyLibrary;
using namespace std;

LibraryUserInterface ui;
int main(int argc, char **argv)
{
	
	ui.printMSG("Resources/Hello_Message.txt");
	ui.login();
	ui.run();
	system("PAUSE");
	return 0;
}
