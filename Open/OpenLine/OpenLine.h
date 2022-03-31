#pragma once
#include "OpenLineInclude.h"

#define DIV 1024
#define WIDTH 7

#define BLACK			0
#define BLUE		 	1
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

namespace fs = std::filesystem;
namespace OpenLine {
	class Function {
	public:
		void Link(std::string& link);
		void Link(std::string&& link);
		void FLink(std::string& link);
		void cowsay(std::string_view text); 
		void tux(std::string_view text) ;
		void banner();
	    void Operation(std::string_view oper);		
		void Succes(std::string_view oper);
		void Error(std::string_view oper);
		void print(auto prints, auto a);
		void cmds();
	};
};
