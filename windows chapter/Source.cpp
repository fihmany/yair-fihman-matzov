#include <windows.h>
#include <stdio.h>

#define STR_SIZE 100

void writeTimeToFile();
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void whereIsWindows();
 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	MSG msg = { 0 };
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
	wc.lpszClassName = L"minwindowsapp";
	if (!RegisterClass(&wc))
		return 1;

	HWND hWnd = CreateWindow(L"minwindowsapp", L"Sample Windpw", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
		

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int counter = 0;
	wchar_t num[10] = { 0 };
	switch (message)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_RBUTTONDOWN:
		counter++;
		break;
	case WM_LBUTTONDOWN:
		wsprintf(num, L"%d", counter);
		SetWindowText(hWnd, (LPCWSTR) num);
		break;
	case WM_KEYDOWN:
	{
		if (wParam == 13)
		{
			writeTimeToFile();
		}
		else if (wParam == '1' || wParam == 97)
		{
			whereIsWindows();
		}
		else
		{
			wsprintf(num, L"%d", wParam);
			MessageBox(NULL, num, L"Test", NULL);
		}
		break;
	}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}

void whereIsWindows()
{
	LPCWSTR buffer[STR_SIZE] = { 0 };
	GetSystemDirectory((LPWSTR) buffer, STR_SIZE);
	MessageBox(NULL, (LPCWSTR) buffer, L"Test", NULL);
}


void writeTimeToFile()
{
	HANDLE hFile = CreateFile(L"C:\\Users\\Yair\\Documents\\Visual Studio 2017\\Projects\\Project1\\Debug\\log.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	DWORD writtenBytes;
	SYSTEMTIME st;
	wchar_t time[9] = { 0 };
	GetLocalTime(&st);
	wsprintf(time, L"%d:%d:%d", st.wHour, st.wMinute, st.wSecond);
	//printf("%s", time);
	WriteFile(hFile, time, sizeof(wchar_t) * 9, &writtenBytes, NULL);
	CloseHandle(hFile);
}