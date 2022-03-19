#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <algorithm>
#include <string>
#include <string_view>
#include <fstream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;
	
std::fstream file;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
