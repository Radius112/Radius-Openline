#include "OpenLineInclude.h"
#include "OpenLine.h"
OpenLine::Function func;
int main()
{

	std::string text;
	while (text != "exit") {
		time_t now = time(0);

		SetConsoleTextAttribute(h, 10);
		std::cout << "<Radius/OpenLine>";
		SetConsoleTextAttribute(h, 11);

		std::getline(std::cin, text);
		std::transform(text.begin(), text.end(), text.begin(), ::tolower);
		STARTUPINFO startinfo = { 0 };
		PROCESS_INFORMATION processinfo = { 0 };
     
		if (text == "notepad") {
			system("notepad.exe");
		}
		else if (text == "cls" || text == "clear")
		{
			system("cls");
		}
		else if (text == ".time")
		{
			char* date_time = ctime(&now);
			std::cout << date_time;
		}
		else if (text == ".math")
		{
			double num1, num2;
			std::cout << "divide = / , Multiplication = * , plus = + \n";
			std::cout << "Enter 2 numbers: \n";
			std::cin >> num1 >> num2;
			std::cout << "What operation do you want to use?\n";
			std::string operation;
			std::cin >> operation;
			if (operation == "/")
			{
				std::cout << num1 / num2 << "\n";
			}
			else if (operation == "+")
			{
				std::cout << num1 + num2 << "\n";
			}
			else if (operation == "*")
			{
				std::cout << num1 * num2 << "\n";
			}

		}
		else if (text == ".cowsay")
		{
			std::cout << "cowsay ";
			std::string user;
			std::getline(std::cin, user);
			func.cowsay(user);
		}
		else if (text == ".cowsay.tux")
		{
			std::cout << "cowsay tux ";
			std::string user;
			std::getline(std::cin, user);
			func.tux(user);
		}
		else if (text == "calc")
		{
			system("calc.exe");
		}
		else if (text == "sdown")
		{
			system("c:\\windows\\system32\\shutdown /s");
		}
		else if (text == "rstart")
		{
			system("c:\\windows\\system32\\shutdown /r");
		}
		else if (text == "exit")
		{
			exit(3);
		}
		else if (text == ".openlink")
		{
		
			std::string link;
			std::cout << "Link: ";
			std::getline(std::cin, link);
			func.Link(link);
		}
		else if (text == ".openflink")
		{
			std::string link;
			std::cout << "Link: ";
			std::getline(std::cin, link);
			func.FLink(link);
		}
		else if (text == ".info")
		{
			SetConsoleTextAttribute(h, 12);
			func.banner();
			std::cout << "Made by Radius (you can only use this on windows)\n";
			SetConsoleTextAttribute(h, 9);
			std::cout << "CMDS: \n";
			SetConsoleTextAttribute(h, 11);
			func.print("math");
			func.print("youtube");
			func.print(".time");
			func.print(".info");
			func.print("notepad");
			func.print("calc");
			func.print("sdown");
			func.print("opera");
			func.print("exit");
			func.print("cls");
			func.print(".cowsay");
			func.print(".cowsay.tux");
			func.print(".openlink");
			func.print(".openflink");
			func.print(".openflink");
			func.print(".cfile");
			func.print(".gpath");
			func.print(".rstart");
		}
		else if (text == "youtube" || text == "yt")
        {
		func.Link("youtube.com");
		}
		else if (text == ".cfile")
        {
		  std::string filename;
		  std::getline(std::cin,filename);
		  if (filename.find(".txt") != std::string::npos)
		  {
			  func.Operation("Valid txt file.(CREATED TXT)");
		  }
		  else
		  {
			  func.Error("NO .txt IN FILE NAME (ADDING TXT..)\n(DONE ADDING .TXT)\n(CREATED TXT)");
			  filename += ".txt";
		  }
		  std::cout << "type \\n for a new line\n";
		  std::getline(std::cin, text);
		  file.open(filename, std::ios::out);
		  if(file.is_open())
		  {
			  file << text;
			  file.close();
		  }
		  std::cout << "File is at " << fs::current_path() << "\n";
		  
		  file.open(filename);
        }
 		else if (text == ".gpath")
        {
		  std::cout << fs::current_path() << "\n";
        }
		else {}
	}
}