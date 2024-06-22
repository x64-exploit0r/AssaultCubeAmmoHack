#include<Windows.h>
#include<iostream>
using namespace std;
int main() {

	DWORD pid  = NULL;
	DWORD AmmoHealth = 0x0089E8E0;
	int Ammo;
	int NewAmmo = 9999;

	cout << "            /$$$$$$  /$$   /$$                                     /$$           /$$   /$$      /$$$$$$          "<< endl;
	cout << "           /$$__  $$| $$  | $$                                    | $$          |__/  | $$     /$$$_  $$          "<< endl;
	cout << " /$$   /$$| $$  \\__/| $$  | $$        /$$$$$$  /$$   /$$  /$$$$$$ | $$  /$$$$$$  /$$ /$$$$$$  | $$$\\ $$  /$$$$$$ "<< endl;
	cout << "|  $$ /$$/| $$$$$$$ | $$$$$$$$       /$$__  $$|  $$ /$$/ /$$__  $$| $$ /$$__  $$| $$|_  $$_/  | $$ $$ $$ /$$__  $$"<< endl;
	cout << " \\  $$$$/ | $$__  $$|_____  $$      | $$$$$$$$ \\  $$$$/ | $$  \\ $$| $$| $$  \\ $$| $$  | $$    | $$\\ $$$$| $$  "<< endl;
	cout << "  >$$  $$ | $$  \\ $$      | $$      | $$_____/  >$$  $$ | $$  | $$| $$| $$  | $$| $$  | $$ /$$| $$ \\ $$$| $$     "<< endl;
	cout << " /$$/\\  $$|  $$$$$$/      | $$      |  $$$$$$$ /$$/\\  $$| $$$$$$$/| $$|  $$$$$$/| $$  |  $$$$/|  $$$$$$/| $$     "<< endl;
	cout << "|__/  \\__/ \\______/       |__//$$$$$$\\_______/|__/  \\__/| $$____/ |__/ \\______/ |__/   \\___/   \\______/ |__/     "<< endl;
	cout << "                             |______/                   | $$                                                      " << endl;
	cout << "                                                        | $$                                                      "<< endl;
	cout << "                                                        |__/                                                     " << endl;
	
	if (IsDebuggerPresent()) {
		cout << "Debugger found" << endl;
		cout << "Exitting :( " << endl;
		system("pause");
		exit(0);
	}
	HWND hand = FindWindowA(0, ("AssaultCube"));
	GetWindowThreadProcessId(hand, &pid);

	HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	cout << "[+]PID - " << pid << endl;
	if (pid == NULL) {
		cout << "Game not Found!!" << endl;
		exit(0);
	}
	ReadProcessMemory(process, (void*)AmmoHealth, &Ammo, sizeof(Ammo), 0);
	cout << "[+] Ready to Hack!" << endl;
	system("pause");

	WriteProcessMemory(process, (void*)AmmoHealth, &NewAmmo, sizeof(NewAmmo), 0);
	
}
