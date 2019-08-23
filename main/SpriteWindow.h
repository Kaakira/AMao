#pragma once
#include <Windows.h>
#include "resources.h"
#include "TrayIcon.h"

using namespace std;

class SpriteWindow
{
private:
	HINSTANCE instance;
	HWND window = NULL;
	SIZE windowSize;
	LPCSTR windowTitle;
	LPCSTR windowClassName;

	HDC hdcSrc = NULL;
	HDC hdcDst = NULL;


public:
	SpriteWindow(LPCSTR className, HINSTANCE hInstance, LPCSTR wndTitle, SIZE wndsize);

	~SpriteWindow();

	// ��������
	HWND CreateIrrWindow(POINT point);
	// �ػ�
	void RedrawWndFrame();

};

