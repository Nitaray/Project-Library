#include <iostream>
#include <stdio.h>

#include "core.h"

using namespace std;

void Process();


int main(int narg, char** argv) {
    Initialization();
    Process();
    Finalization();
    return 0;
}