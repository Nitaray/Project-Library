#include <bits/stdc++.h>
#include "LibraryContext.h"
using namespace MyLibrary;
using namespace std;

int main(int argc, char **argv)
{
	LibraryContext lib;
	shared_ptr<Manager>tempman;
	lib.readData();
	lib.makeBorrow(51,71);
	lib.releaseBorrow(51,71);
	lib.writeData();
	return 0;
}
