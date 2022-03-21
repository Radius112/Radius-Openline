#include "OpenLineInclude.h"
#include "OpenLine.h"
OpenLine::Function func;
int main()
{
	TCHAR username[UNLEN + 1];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)username, &size);
	std::string text;
	while (text != "exit") {
		time_t now = time(0);

		SetConsoleTextAttribute(h, LIGHTGREEN);
		std::wcout << username;
		SetConsoleTextAttribute(h, WHITE);
		std::cout << ":";
		SetConsoleTextAttribute(h, BLUE);
		std::cout << "~";
		SetConsoleTextAttribute(h, WHITE);
		std::cout << "#";
		SetConsoleTextAttribute(h, BLUE);
	
		std::getline(std::cin, text);

		SetConsoleTextAttribute(h, WHITE);
		std::transform(text.begin(), text.end(), text.begin(), ::tolower);

		STARTUPINFO startinfo = { 0 };
		PROCESS_INFORMATION processinfo = { 0 };
     
		if      (text == "notepad") {
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
		else if (text == ".calc")
		{
			system("calc.exe");
		}
		else if (text == ".sdown")
		{
			system("c:\\windows\\system32\\shutdown /s");
		}
		else if (text == ".rstart")
		{
			system("c:\\windows\\system32\\shutdown /r");
		}
		else if (text == ".exit")
		{
			exit(3);
		}
		else if (text == ".open.link")
		{
		
			std::string link;
			std::cout << "Link: ";
			std::getline(std::cin, link);
			func.Link(link);
		}
		else if (text == ".open.flink")
		{
			std::string link;
			std::cout << "Link: ";
			std::getline(std::cin, link);
			func.FLink(link);
		}
		else if (text == ".info")
		{
			SetConsoleTextAttribute(h, RED);
			func.banner();
			std::cout << "Made by Radius (you can only use this on windows)\n";
			SetConsoleTextAttribute(h, WHITE);
			std::cout << "CMDS: \n";
			SetConsoleTextAttribute(h, WHITE);
			func.cmds();
		}
		else if (text == ".youtube" || text == ".yt")
		{
			func.Link("youtube.com");
		}
		else if (text == ".ctxt")
		{
		std::string yes_no;
		  std::string filename;
		  std::cout << "Enter file name: ";
		  std::getline(std::cin,filename);
		  if (filename.find(".txt") != std::string::npos)
		  {
			  func.Succes("Created txt");
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
		  std::cout << "File is at " << fs::current_path() << "\\" << filename << "\n";
		  std::cout << "Do you want to open the file? [Y/N]\n";
		  std::getline(std::cin, yes_no);
		  std::transform(yes_no.begin(), yes_no.end(),yes_no.end(), ::tolower);
		  std::string curpath = fs::current_path().string();
		  std::string o_file = curpath + "\\" + filename;
		  if(yes_no == "y")
		  {
			  ShellExecuteA(NULL, "open", o_file.c_str(), NULL, NULL, SW_SHOWDEFAULT);
		  }
		  else if(yes_no == "n")
		  {
		  }
        }
		else if (text == ".big.txt")
        {
		   std::ofstream file2;
	       std::string filename;
	       std::string yes_no;
	       std::cout << "Enter file name: ";
	       std::getline(std::cin, filename);
	       if (filename.find(".txt") != std::string::npos)
	       {
	         	func.Succes("Created txt");
	       }
	       else {
	       	  func.Error("NO .txt IN FILE NAME (ADDING TXT..)\n(DONE ADDING .TXT)\n(CREATED TXT)");
	       	  filename += ".txt";
	          }
		   std::cout << "Type escape txt. to stop typing.\n";
		   file2.open(filename, std::ios::app);
		   if (file2.is_open()){
			 while (text != "escape txt.") {
				 std::getline(std::cin, text);
				 file2 << text << "\n";
			 }
		   }
		   std::string curpath = fs::current_path().string();
		   std::string o_file = curpath + "\\" + filename;
		   std::cout << "File is at " << fs::current_path() << "\n";
		   std::cout << "Do you want to open the file? [Y/N]\n";
		   std::getline(std::cin, yes_no);
		   std::transform(yes_no.begin(), yes_no.end(), yes_no.end(), ::tolower);
		   if (yes_no == "y")
		   {
			   ShellExecuteA(NULL, "open", o_file.c_str(), NULL, NULL, SW_SHOWDEFAULT);
		   }
		}
		else if (text == ".dump")
		{
		  std::ifstream dump;
	   	  std::string dums;
		  std::cout << "path: ";
		  std::getline(std::cin, dums);
		  dump.open(dums);
		  std::cout << "dump: \n";
		  if (dump.is_open())
			  std::cout << dump.rdbuf()  << "\n";
		}
		else if (text == ".open.file")
		{
			std::string loc;
			std::string userin;
			std::cout << "Please enter file path: ";
			std::getline(std::cin, loc);
			std::cout << "Do you want to open this as administrator[Y][N]\n";
			std::getline(std::cin, userin);
			std::transform(userin.begin(), userin.end(),  userin.end(), ::tolower);
			if(userin == "y")
			{ 
				ShellExecuteA(NULL, "runas", loc.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
			else if (userin == "n")		
			{
				ShellExecuteA(NULL, "open", loc.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
		}
 		else if (text == ".main.path")
        {
	    	std::string cur = fs::current_path().string();
		    ShellExecuteA(NULL, "open", cur.c_str(), NULL, NULL, SW_SHOWDEFAULT);
		    std::cout << fs::current_path() << "\n";
        }
		else if (text == ".ipc")
        {
		  int ip =  system("C:\\Windows\\System32\\ipconfig");
		  ip;
        }
		else if (text == ".chmap")
        {
		   system("charmap");
        }
		else if (text == ".re.file")
        {
		   std::string path;
		   std::string change;
		   std::string change2;
		   std::cout << "path (DONT INCLUDE THE FILENAME YOU WANT TO CHANGE): ";
		   std::getline(std::cin, path);
		   fs::path p = path;
		   std::cout << "File Name: ";
		   std::getline(std::cin, change);
		   std::cout << "New name: ";
		   std::getline(std::cin, change2);
		   fs::rename(p / change, p / change2);
        }
		else if (text == ".del.file")
        {
		   std::string paths;
		   std::ofstream(paths.c_str());
		   std::cout << "Ennter path: ";
		   std::getline(std::cin, paths);

		   std::remove(paths.c_str());
		}
		else if (text == ".cr.dir")
        {
		    std::string dir;
			std::string dirname;
			std::string opendr;

		    std::cout << "Where should the dir be?:  ";

			std::getline(std::cin, dir);
			fs::current_path(dir);

			std::cout << "dir name: ";
			std::getline(std::cin, dirname);

		    std::string directory_name(dirname);
			fs::create_directory(directory_name);

			std::cout << "Open dir?[Y][N]: ";
			std::getline(std::cin, opendr);

			std::transform(opendr.begin(), opendr.end(), opendr.end(), ::tolower);
			std::string path = dir + "\\" + dirname;
			if (opendr == "y") {
				ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
		}
		else if (text == ".open.path")
        {
		   std::string path;
		   std::cout << "path: ";
		   std::getline(std::cin, path);
		   ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWDEFAULT);

        }
		else {}	
	}
}
