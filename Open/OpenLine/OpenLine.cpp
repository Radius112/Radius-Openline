#pragma once
#include "OpenLine.h"

void OpenLine::Function::Link(std::string& link)
{
	std::string bind = "start ";
	std::string www = "https:www.";
	std::string output = bind + www + link;
	system(output.c_str());
}
void OpenLine::Function::Link(std::string&& link)
{
	std::string bind = "start ";
	std::string www = "https:www.";
	std::string output = bind + www + link;
	system(output.c_str());
}
void OpenLine::Function::FLink(std::string& link)
{
		std::string bind = "start ";
		std::string output = bind + link;
		system(output.c_str());
}
void OpenLine::Function::cowsay(std::string_view text)
{
		std::cout << "___________________________________________________________________\n"
				<< "                                                                    \n"
				<< "          < " << text << " > \n"
				"-------------------------------------------------------------------";
			std::cout << "\n"
				"             \\  ^__^\n"
				"              \\ (oo)\\_______ \n"
				"                (__) \\       )\\/\\ \n"
				"                 ||----w |\n"
				"                 ||     ||\n";
}
void OpenLine::Function::tux(std::string_view text)
{
	std::cout << "___________________________________________________________________\n"
				<< "                                                                   \n"
				<< "           < " << text << " > \n"
				"------------------------------------------------------------------- \n";
			std::cout << "                \\ \n"
				"                 \\ \n"
				"                   .--.\n"
				"                  |o_o |\n"
				"                  |:_/ |\n"
				"                   \\ \\ \n"
				"                (|     | ) \n"
				"               /'\\_   _/`\\ \n"
				"               \\___)=(___/ \n";
}
void OpenLine::Function::banner()
{
		std::cout << "'########:::::'###::::'########::'####:'##::::'##::'######::::::::'##::'#######::'########::'########:'##::: ##:'##:::::::'####:'##::: ##:'########:\n";
		std::cout << " ##.... ##:::'## ##::: ##.... ##:. ##:: ##:::: ##:'##... ##::::::'##::'##.... ##: ##.... ##: ##.....:: ###:: ##: ##:::::::. ##:: ###:: ##: ##.....::\n";
		std::cout << " ##:::: ##::'##:. ##:: ##:::: ##:: ##:: ##:::: ##: ##:::..::::::'##::: ##:::: ##: ##:::: ##: ##::::::: ####: ##: ##:::::::: ##:: ####: ##: ##:::::::\n";
		std::cout << " ########::'##:::. ##: ##:::: ##:: ##:: ##:::: ##:. ######:::::'##:::: ##:::: ##: ########:: ######::: ## ## ##: ##:::::::: ##:: ## ## ##: ######:::\n";
		std::cout << " ##.. ##::: #########: ##:::: ##:: ##:: ##:::: ##::..... ##:::'##::::: ##:::: ##: ##.....::: ##...:::: ##. ####: ##:::::::: ##:: ##. ####: ##...::::\n";
		std::cout << " ##::. ##:: ##.... ##: ##:::: ##:: ##:: ##:::: ##:'##::: ##::'##:::::: ##:::: ##: ##:::::::: ##::::::: ##:. ###: ##:::::::: ##:: ##:. ###: ##:::::::\n";
		std::cout << " ##:::. ##: ##:::: ##: ########::'####:. #######::. ######::'##:::::::. #######:: ##:::::::: ########: ##::. ##: ########:'####: ##::. ##: ########:\n";
		std::cout << "..:::::..::..:::::..::........:::....:::.......::::......:::..:::::::::.......:::..:::::::::........::..::::..::........::....::..::::..::........::\n";
}
void OpenLine::Function::Operation(std::string_view oper)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		    SetConsoleTextAttribute(h, 9);
			std::cout << "Output: \n";
			std::cout << oper << "\n";
			SetConsoleTextAttribute(h, WHITE);
}
void OpenLine::Function::Succes(std::string_view oper)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(h, WHITE);
				std::cout << "Succes: " << oper << "\n";
				SetConsoleTextAttribute(h, WHITE);
}
void OpenLine::Function::Error(std::string_view oper)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(h, RED);
			std::cout << "ERROR: ";
			std::cout << oper << "\n";
			SetConsoleTextAttribute(h, WHITE);
}
void OpenLine::Function::print(auto prints, auto a)
{
	std::cout << prints << "    (" << a << ")" << "\n";
}
void OpenLine::Function::cmds()
{
		print(".youtube", "Opens youtube link");
		print(".time", "shows the current time");
		print(".info", "you just used this lol");
		print(".notepad", "opens notepad");
		print(".calc", "opens the calculator");
		print(".sdown", "shutdowns the computer");
		print(".exit", "exit out of the application");
		print(" cls", "clears the console");
		print(".cowsay", "use it to see what it does");
		print(".cowsay.tux", "use it to see what it does");
		print(".open.link", "opens the link you type");
		print(".open.flink", "does the same as .open.link but you also need to add www and https");
		print(".c.txt", "Creates a txt file");
		print(".main.path", "opens the application path");
		print(".rstart", "restarts the computer");
		print(".ipc", "shows ip info");
		print(".chmap", "char map");
		print(".big.txt", "same as .c.txt but you can type enter");
		print(".cr.dir", "creates a dir");
		print(".del.file","deletes a file");
		print(".dump","dumps all the text");
		print(".open.path","opens path");
		print(".search", "google search");
		print(".cpy.file", "copy file to a other file");
		print(".info.dir", "information fomr a dir");
		print(".info.file", "information from a file");
		print(".info.hwd", "your hardware information");
		print(".cd", "go into a file");
		print(".cd.", "go to parent file");
		print(".cd/", "go to root path");
}

