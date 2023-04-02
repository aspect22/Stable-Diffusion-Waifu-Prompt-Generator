#include <iostream>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void Menu();
void Generate_Prompt_Basic_Questions();
void Generate_Prompt_Advanced_Questions();
void Generate_Prompt_Horny();
void Instructions();
void ClearScreen();
void Settings();
string Prompt_Builder_Advanced();
string Prompt_Builder_Basic();
string Prompt_Builder_Horny();