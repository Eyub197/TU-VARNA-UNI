#pragma once
#include "constants.h"
#include <string>

bool isValidName(const char* name);
bool isValidInt(int &result, int min, int max);
void checkForSimpleNumber(int &result, std::string message);
void clearBuffer();
