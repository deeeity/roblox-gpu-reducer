// HeadlessRoblox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>

HWND handle;
bool toggled = false;

int main()
{
	SetConsoleTitle(TEXT("Get that 80% 'outta here boi"));
	std::cout << "Roblox GPU Reducer Tool - deity#0228\n\n"
		<< "Press [F1] to toggle state.\nPress [END] to stop program.\n\n";
	while (!GetAsyncKeyState(VK_END) & 1)
	{
		std::cout << "\rState: " << (toggled ? "on " : "off");
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			toggled = !toggled;
		}

		if (!toggled)
		{
			if(handle != 0)
				PostMessage(handle, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		}
		else
		{
			handle = FindWindow(0, TEXT("Roblox"));

			if (handle != 0)
				PostMessage(handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}

		Sleep(100);
	}

	return 0;
}