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
#include <shellapi.h>
#include <Lmcons.h>
#include <direct.h>
namespace fs = std::filesystem;
	
std::fstream file;
std::ofstream file2;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
