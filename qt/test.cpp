#include<Windows.h>
#include<iostream>
using namespace std;
#pragma comment(linker,"/subsystem:\"console\" /entry:\"WinMainCRTStartup\" ")

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nCmdShow) {
	cout << hlnstance <<'\t' << hPrevlnstance<<'\t' << GetModuleHandle(NULL) << endl;
	cout << "11111112121212121212121212121212121212121212" << endl;
	cout << GetCommandLineA() << endl;
	cout << "11111112121212121212121212121212121212121212" << endl;
	cout << nCmdShow<<'\t' << SW_SHOWDEFAULT << endl;
	cout << "11111112121212121212121212121212121212121212" << endl;
	MessageBox(0, "212121212","dwedewdewd", MB_OK);

	return 0;

}