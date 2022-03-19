#pragma once
#include "OpenLineInclude.h"
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15

namespace OpenLine {
	class Function {
	public:
		void Link(std::string&& link)
		{
			std::string bind = "start ";
			std::string www = "https://www.";
			std::string output = bind + www + link;
			system(output.c_str());

		}
		void FLink(std::string&& link)
		{
			std::string bind = "start ";
			std::string output = bind + link;
			system(output.c_str());

		}
		void FLink(std::string& link)
		{
			std::string bind = "start ";
			std::string output = bind + link;
			system(output.c_str());

		}
		void Link(std::string& link)
		{
			std::string bind = "start ";
			std::string www = "https://www.";
			std::string output = bind + www + link;
			system(output.c_str());

		}
		void cowsay(std::string_view text) {
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
		void tux(std::string_view text) {
			std::cout << "___________________________________________________________________\n"
				<< "                                                                   \n"
				<< "           < " << text << " > \n"
				"------------------------------------------------------------------- \n";
			std::cout << "                \\ \n"
				"                 \\ \n"
				"                   .--.\n"
				"                  |o_o |\n"
				"                  |:_/ |\n"
				"                 //  \\ \\ \n"
				"                (|     | ) \n"
				"               /'\\_   _/`\\ \n"
				"               \\___)=(___/ \n";
		}
		void banner()
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
		void Operation(std::string_view oper)
		{
			SetConsoleTextAttribute(h, 9);
			std::cout << "Output: \n";
			std::cout << oper << "\n";
			SetConsoleTextAttribute(h, GREEN);
		}
		void Error(std::string_view oper)
		{
			SetConsoleTextAttribute(h, RED);
			std::cout << "ERROR: \n";
			std::cout << oper << "\n";
			SetConsoleTextAttribute(h, GREEN);
		};
		void print(auto prints)
		{
			SetConsoleTextAttribute(h, BLUE);
			std::cout << prints << "\n";
		}
	};
};