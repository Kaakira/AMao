#pragma once
#include <Windows.h>
#include "FrameHandler.h"
#include "SpriteAnimation.h"

struct SpriteConfiguration {
	SIZE size;
	POINT position;
	HINSTANCE hand;
};


// ����ʵ����ȫ��ֻ�����һ������ʵ��
class SpriteInstance
{
private:
	const LPCSTR MAIN_WINDOW_CLASSNAME = "AMao_Main";
	SpriteConfiguration configuration = { 0 };
	HWND mainWindow = NULL;
	FrameHandler* frameHand = NULL;

	SpriteInstance()
	{
	}

	~SpriteInstance()
	{
	}

	static LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	void GenerateWindowHand();

public:
	static SpriteInstance* GetInstance() {
		static SpriteInstance instance;
		return &instance;
	}
	void Ready(SpriteConfiguration config);
	void Start();
	void Show();
	void Hidden();
	void Shutdown();
};

