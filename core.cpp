//
// Created by Nguyen Duc Dung on 2019-02-15.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

/// Prototype declaration
void Initialization();
void Finalization();

void LoadConfiguration();
void LoadMenu();
void DisplayMenu();
void ProcessUserChoice();
///--------------------------------------------------------------------

bool __coreInitialized = false;  /// an example of global variable
int  __userChoice;               /// a global variable to store user choice
bool __isExiting = false;        /// this variable should be turn on when the program exits
// TODO: add more global variables to complete tasks

///--------------------------------------------------------------------
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */
void Initialization() {
    LoadConfiguration();
    LoadMenu();
    // TODO: write the code to initialize the program
    __coreInitialized = true;
}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization() {
    // TODO: write the code to clean up when the program exits
}

void LoadConfiguration() {
    // TODO: write code to load data from the configuration file

}

void LoadMenu() {
    // TODO: write code to load menu from the configuration file
    
}

void DisplayMenu() {
    // TODO: Display the menu loaded from configuration file
}

void ProcessUserChoice() {
    // TODO: Read user input and process
    
}