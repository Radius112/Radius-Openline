#include "OpenLineInclude.h"
#include "OpenLine.h"
OpenLine::Function func;
std::string get_last_word(std::string s) {
	auto index = s.find_last_of("\\");
	std::string last_word = s.substr(++index);
	std::replace(last_word.begin(), last_word.end(), '#', ' ');
	return last_word;
}

int main()
{  
    std::fstream file;
    std::ifstream file2;
	//the username
	TCHAR username[UNLEN + 1];
	//the max size of the username chars
	DWORD size = UNLEN + 1;

	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	//gets the username 
	GetUserName((TCHAR*)username, &size);
	std::string input;
	//gets set to true if you use cd
	bool cd = false;
	//the path variable for cd
	std::string cdpath;
	while (input != "exit") {
		time_t now = time(0);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, LIGHTGREEN);
		std::wcout << username;
		SetConsoleTextAttribute(h, WHITE);
		std::cout << ":";
		SetConsoleTextAttribute(h, BLUE);
		std::cout << "~";
		if (cd)
			std::cout << "/" << get_last_word(cdpath);

		SetConsoleTextAttribute(h, WHITE);
		std::cout << "-";
		SetConsoleTextAttribute(h, BLUE);

		std::getline(std::cin, input);
		SetConsoleTextAttribute(h, WHITE);
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);

		STARTUPINFO startinfo = { 0 };
		PROCESS_INFORMATION processinfo = { 0 };

		if (input == "notepad") {
			system("notepad.exe");
		}
		else if (input == "cls" || input == "clear")
		{
			//just clears the console idiot.
			system("cls");
		}
		else if (input == ".time")
		{
			//gets the date and time
			const char* time_date = ctime(&now);
			//prints it
			std::cout << time_date;
		}
		else if (input == ".cowsay")
		{

			std::cout << "cowsay ";
			std::string user;
			std::getline(std::cin, user);
			func.cowsay(user);
		}
		else if (input == ".cowsay.tux")
		{
			std::cout << "cowsay tux ";
			std::string user;
			std::getline(std::cin, user);
			func.tux(user);
		}
		else if (input == ".calc")
		{
			system("calc.exe");
		}
		else if (input == ".sdown")
		{
			system("c:\\windows\\system32\\shutdown /s");
		}
		else if (input == ".rstart")
		{
			system("c:\\windows\\system32\\shutdown /r");
		}
		else if (input == ".exit")
		{
			exit(3);
		}
		else if (input == ".open.link")
		{

			std::string link;
			std::cout << "Link: ";
			std::getline(std::cin, link);
			func.Link(link);
		}
		else if (input == ".open.flink")
		{
			std::string link;
			std::cout << "Link: ";
			std::getline(std::cin, link);
			func.FLink(link);
		}
		else if (input == ".help")
		{
			SetConsoleTextAttribute(h, RED);
			func.banner();
			std::cout << "Made by Radius (you can only use this on windows)\n";
			SetConsoleTextAttribute(h, WHITE);
			std::cout << "CMDS: \n";
			SetConsoleTextAttribute(h, WHITE);
			func.cmds();
		}
		else if (input == ".youtube" || input == ".yt")
		{
			func.Link("youtube.com");
		}
		else if (input == ".c.txt")
		{
			std::string yes_no;
			std::string filename;
			std::string text;
			std::cout << "Enter file name: ";
			std::getline(std::cin, filename);
			if (cd)
			{
				std::string a;
				a += cdpath + "\\" + filename;
				filename = a;
			}
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
			if (file.is_open())
			{
				file << text;
				file.close();
			}
			std::cout << "File is at " << filename << "\n";
			std::cout << "Do you want to open the file? [Y/N]\n";
			std::getline(std::cin, yes_no);
			std::transform(yes_no.begin(), yes_no.end(), yes_no.end(), ::tolower);
			std::string curpath = fs::current_path().string();
			if (yes_no == "y")
			{
				ShellExecuteA(NULL, "open", filename.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
			else if (yes_no == "n")
			{
			}
		}
		else if (input == ".big.txt")
		{
			std::ofstream file2;
			std::string filename;
			std::string yes_no;
			std::string text;
			std::cout << "Enter file name: ";
			std::getline(std::cin, filename);
			if (cd)
			{
				std::string a;
				a += cdpath + "\\" + filename;
				filename = a;
			}
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
			if (file2.is_open()) {
				while (text != "escape txt.") {
					std::getline(std::cin, text);
					file2 << text << "\n";
				}
			}
			std::cout << "File is at " << filename << "\n";
			std::cout << "Do you want to open the file? [Y/N]\n";
			std::getline(std::cin, yes_no);
			std::transform(yes_no.begin(), yes_no.end(), yes_no.end(), ::tolower);
			if (yes_no == "y")
			{
				ShellExecuteA(NULL, "open", filename.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
		}
		else if (input == ".dump")
		{
			std::ifstream dump;
			std::string dums;
			std::cout << "path: ";
			std::getline(std::cin, dums);
			if (cd)
			{
				std::string a;
				a += cdpath + "\\" + dums;
				dums = a;
			}
			dump.open(dums);
			std::cout << "dump: \n";
			if (dump.is_open())
				std::cout << dump.rdbuf() << "\n";

		}
		else if (input == ".open.file")
		{
			std::string loc;
			std::string userin;
			if (!cd) {
				std::cout << "Please enter file path: ";
				std::getline(std::cin, loc);
			}
			if (cd)
			{
				std::cout << "Please enter file name: ";
				std::getline(std::cin, loc);
				std::string a;
				a += cdpath + "\\" + loc;
				loc = a;
			}
			std::cout << "Do you want to open this as administrator[Y][N]\n";
			std::getline(std::cin, userin);
			std::transform(userin.begin(), userin.end(), userin.end(), ::tolower);
			if (userin == "y")
			{
				ShellExecuteA(NULL, "runas", loc.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
			else if (userin == "n")
			{
				ShellExecuteA(NULL, "open", loc.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
		}
		else if (input == ".main.path")
		{
			if (cd)
			{
				ShellExecuteA(NULL, "open", cdpath.c_str(), NULL, NULL, SW_SHOWDEFAULT);
				std::cout << cdpath << "\n";
			}
			if (!cd) {
				std::string cur = fs::current_path().string();
				ShellExecuteA(NULL, "open", cur.c_str(), NULL, NULL, SW_SHOWDEFAULT);
				std::cout << fs::current_path() << "\n";
			}
		}
		else if (input == ".ipc")
		{
			int ip = system("C:\\Windows\\System32\\ipconfig");
			ip;
		}
		else if (input == ".chmap")
		{
			system("charmap");
		}
		else if (input == ".re.file")
		{
			std::string path;
			std::string change;
			std::string change2;
			if (cd)
			{
				std::string a;
				a += cdpath + "\\" + path;
				path = a;
			}
			if (!cd)
			{
				std::cout << "path (DONT INCLUDE THE FILENAME YOU WANT TO CHANGE): ";
				std::getline(std::cin, path);
			}
			fs::path p = path;
			std::cout << "File Name: ";
			std::getline(std::cin, change);
			std::cout << "New name: ";
			std::getline(std::cin, change2);
			fs::rename(p / change, p / change2);
		}
		else if (input == ".del.file")
		{
			std::string paths;
			std::ofstream(paths.c_str());
			if (!cd)
				std::cout << "Enter path: ";
			if (cd)
				std::cout << "Enter file name:";

			std::getline(std::cin, paths);

			if (cd)
			{
				std::string a;
				a += cdpath + "\\" + paths;
				paths = a;
			}
			std::remove(paths.c_str());
		}
		else if (input == ".del.files")
		{
			std::string filecounts;
			std::string paths;
			std::ofstream(paths.c_str());
			std::cout << "How many files? ";
			std::getline(std::cin, filecounts);
			int filecount = std::stoi(filecounts);
			if (!cd) {
				std::cout << "Enter path: ";
				std::getline(std::cin, paths);
				for (size_t i = 0; i < filecount; i++)
				{
					std::string delfilename;
					std::cout << "enter file name: ";
					std::getline(std::cin, delfilename);
					paths += "\\" + delfilename;
					std::cout << paths << "\n";
					std::remove(paths.c_str());

					const auto pos = paths.find_last_of("\\");
					paths = paths.substr(0, pos);
				}
			}

			if (cd)
			{
				std::string a;
				a += cdpath + "\\" + paths;
				paths = a;

				for (size_t i = 0; i < filecount; i++)
				{
					std::string delfilename;
					std::cout << "enter file name: ";
					std::getline(std::cin, delfilename);
					paths += "\\" + delfilename;
					std::cout << paths << "\n";
					std::remove(paths.c_str());

					const auto pos = paths.find_last_of("\\");
					paths = paths.substr(0, pos);
				}
			}

		}
		else if (input == ".cr.dir")
		{
			std::string dir;
			std::string dirname;
			std::string opendr;
			if (!cd) {
				std::cout << "Where should the dir be?:  ";
				std::getline(std::cin, dir);
			}
			if (cd)
			{
				std::cout << "dir name: ";
				std::getline(std::cin, dirname);
				dir = cdpath;
			}

			fs::current_path(dir);
			if (!cd) {
				std::cout << "dir name: ";
				std::getline(std::cin, dirname);
			}
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
		else if (input == ".open.path")
		{
			std::string path;
			if (!cd)
				std::getline(std::cin, path);
			if (cd)
			{
				std::getline(std::cin, path);
				std::string a;
				a += cdpath + "\\" + path;
				path = a;
			}
			ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWDEFAULT);
		}
		else if (input == ".search")
		{
			std::string search;
			std::string google = "google.com/search?q=";
			std::cout << "Search: ";
			std::getline(std::cin, search);
			std::replace(search.begin(), search.end(), ' ', '+');
			google += search;
			std::cout << google << "\n";
			func.Link(google);

		}
		else if (input == ".ls")
		{
			std::string path;
			if (cd)
			{
				for (auto& entry : fs::directory_iterator(cdpath)) {
					std::string a = entry.path().string();
					std::cout << get_last_word(a) << "\n";
				}
			}
			else
			{
				std::cout << "enter path: ";
			std:getline(std::cin, path);

				for (auto& entry : fs::directory_iterator(path)) {
					std::string a = entry.path().string();
					std::cout << get_last_word(a) << "\n";
				}
			}

		}
		else if (input == ".info.file")
		{
			std::string path;
			if (cd)
			{
				std::cout << "filename: ";
				std::getline(std::cin, path);
				std::string a;
				a += cdpath + "\\" + path;
				path = a;
			}
			if (!cd) {
				std::cout << "path: ";
				std::getline(std::cin, path);
			}
			const fs::path dir{ path.c_str() };
			std::ifstream dirs;
			std::cout << std::boolalpha
				<< "dir: " << dir << "\n"
				<< "empty: " << fs::is_empty(dir) << "\n"
				<< "file size: " << fs::file_size(dir) << "kb" << "\n";
			dirs.open(path);
			std::cout << "dump: \n";
			if (dirs.is_open())
				std::cout << dirs.rdbuf() << "\n";
		}
		else if (input == ".info.dir")
		{
			std::string path;
			if (cd)
			{
				path = cdpath;
			}
			if (!cd)
				std::getline(std::cin, path);
			const fs::path dir{ path.c_str() };
			std::cout << "Dir content: \n";
			for (const auto& entry : fs::directory_iterator(dir))
				std::cout << entry.path() << "\n";
			std::cout << path << "\n";
			std::cout << std::boolalpha << "Empty:  " << fs::is_empty(path) << "\n";
			std::cout << std::boolalpha << "is dir: " << fs::is_directory(path) << "\n";
		}
		else if (input == ".info.hwd")
		{
			MEMORYSTATUSEX statex;
			statex.dwLength = sizeof(statex);
			GlobalMemoryStatusEx(&statex);
			std::cout << "OEM ID: " << siSysInfo.dwOemId << "\n";
			std::cout << "Proccesors: " << siSysInfo.dwNumberOfProcessors << "\n";
			std::cout << "Page size: " << siSysInfo.dwPageSize << '\n';
			std::cout << "Procces type: " << siSysInfo.dwProcessorType << "\n";
			std::cout << "min application adress: " << siSysInfo.lpMinimumApplicationAddress << "\n";
			std::cout << "max application adress: " << siSysInfo.lpMaximumApplicationAddress << "\n";
			std::cout << "Active proccesor mask: " << siSysInfo.dwActiveProcessorMask << "\n";
			std::cout << "cores: " << siSysInfo.dwNumberOfProcessors << "\n";
			//got from  https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex?redirectedfrom=MSDN not my code
			_tprintf(TEXT("There is  %*ld percent of memory in use.\n"),
				WIDTH, statex.dwMemoryLoad);
			_tprintf(TEXT("There are %*I64d total KB of physical memory.\n"),
				WIDTH, statex.ullTotalPhys / DIV);
			_tprintf(TEXT("There are %*I64d free  KB of physical memory.\n"),
				WIDTH, statex.ullAvailPhys / DIV);
			_tprintf(TEXT("There are %*I64d total KB of paging file.\n"),
				WIDTH, statex.ullTotalPageFile / DIV);
			_tprintf(TEXT("There are %*I64d free  KB of paging file.\n"),
				WIDTH, statex.ullAvailPageFile / DIV);
			_tprintf(TEXT("There are %*I64d total KB of virtual memory.\n"),
				WIDTH, statex.ullTotalVirtual / DIV);
			_tprintf(TEXT("There are %*I64d free  KB of virtual memory.\n"),
				WIDTH, statex.ullAvailVirtual / DIV);
			_tprintf(TEXT("There are %*I64d free  KB of extended memory.\n"),
				WIDTH, statex.ullAvailExtendedVirtual / DIV);
		}
		else if (input == ".cpy.file")
		{
			std::string path;
			std::string file;
			std::string yes;
			std::cout << "File: ";
			std::getline(std::cin, path);
			std::cout << "Copy to: ";
			std::getline(std::cin, file);
			if (cd) {
				std::string a;
				std::string b;

				a += cdpath + "\\" + path;
				path = a;

				b += cdpath + "\\" + file;
				file = b;
			}
			fs::path a(path.c_str());
			fs::path b(file.c_str());
			fs::copy_file(a, b, fs::copy_options::overwrite_existing);
			std::cout << "Want to open the file[Y/N]:  ";
			std::getline(std::cin, yes);
			if (yes == "y")
			{
				ShellExecuteA(NULL, "open", file.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
		}
		else if (input == ".cd")
		{
			std::string path;
			std::cout << "will not check if its a valid path\n";
			std::cout << "Enter a path: ";
			std::getline(std::cin, cdpath);
			cd = true;
			if (cdpath == "exit.cd") {
				cd = false;
				cdpath = "";
			}
		}
		else if (input == ".cd/")
		{
			if (cd) {
				cdpath = fs::current_path().root_path().string();
				while (cdpath.find("\"") != std::string::npos)
					cdpath.replace(cdpath.find("\""), 3, " ");
			}
		}
		else if (input == ".cd.")
		{
			if (cd) {
				const auto pos = cdpath.find_last_of("\\");
				cdpath = cdpath.substr(0, pos);
				std::cout << cdpath << "\n";
			}
		}
		else if (input == ".cd./")
		{
			if (cd) {
				std::string add;
				std::cout << "what file?: ";
				std::getline(std::cin, add);
				cdpath += "\\" + add;
			}
		}
		else if (input == ".cd/d")
		{
			cdpath = fs::current_path().root_path().string();
			while (cdpath.find("\"") != std::string::npos)
				cdpath.replace(cdpath.find("\""), 3, " ");
			std::wstring a = username;
			std::wcout << username << "\n";
			std::string usernamestring(a.begin(), a.end());
			cdpath += "\\Users\\";
			cdpath += usernamestring;
			cdpath += "\\Downloads";
			cd = true;
		}
		else if (input == ".beep")
		{
			std::string dur;
			std::string freq;
			double durc;
			double freqc;
			std::cout << "(in the range of 37 trough 32.767)freq: ";
			std::getline(std::cin, freq);
			std::cout << "(seconds)dur: ";
			std::getline(std::cin, dur);
			durc = stoi(dur);
			durc *= 1000;
			freqc = stoi(freq);
			Beep(freqc, durc);
		}
		else if (input == ".c.file")
		{
			std::string yes_no;
			std::string filename;
			std::string text;
			if (cd)
				std::cout << "Enter file name: ";
			else
				std::cout << "Enter filepath: ";

			std::getline(std::cin, filename);
			if (cd)
			{
				std::string a;
				a += cdpath + "\\" + filename;
				filename = a;
			}

			std::cout << "type \\n for a new line\n";
			std::getline(std::cin, text);
			file.open(filename, std::ios::out);
			if (file.is_open())
			{
				file << text;
				file.close();
			}
			std::cout << "File is at " << filename << "\n";
			std::cout << "Do you want to open the file? [Y/N]\n";
			std::getline(std::cin, yes_no);
			std::transform(yes_no.begin(), yes_no.end(), yes_no.end(), ::tolower);
			if (yes_no == "y")
			{
				ShellExecuteA(NULL, "open", filename.c_str(), NULL, NULL, SW_SHOWDEFAULT);
			}
		}
		else if (input == ".c.txts")
		{
			std::string yes_no;
			std::string filename;
			std::string text;
			std::string files;
			int filecount;
			std::cout << "How many txt files do you want to create?: ";
			std::getline(std::cin, files);
			filecount = std::stoi(files);
			for (size_t i = 0; i < filecount; i++) {
				std::cout << "Enter file name: ";
				std::getline(std::cin, filename);
				if (cd)
				{
					std::string a;
					a += cdpath + "\\" + filename;
					filename = a;
				}
				if (filename.find(".txt") != std::string::npos)
				{
					func.Succes("Created txt");
				}
				else
				{
					filename += ".txt";
				}
				std::cout << "type \\n for a new line\n";
				std::getline(std::cin, text);
				file.open(filename, std::ios::out);
				if (file.is_open())
				{
					file << text;
					file.close();
				}

			}
		
		}
		else if (input ==  "")	
		{
			
		}
		else
		{
			std::cout << "\"" << input << "\"" 
				<< " is not recognized" 
				<< " as a command" << "\n";
		}
    }
}	
