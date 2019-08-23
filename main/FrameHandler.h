#pragma once
#include <Windows.h>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <iostream>
#include <dxgi.h>
#include <map>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "windowscodecs.lib")
using namespace std;

class SpriteFrame {
	const string id;
public:
	static string CeateFrameId();

	string GetFrameId() {
		return id;
	}

	SpriteFrame() :id(SpriteFrame::CeateFrameId()) {
	}
};

class FrameHandler {
private:
	HDC hdcSrc = NULL;
	HDC hdcDst = NULL;
	RECT clientRect;
	SIZE size;
	HWND window;
	// D2D ����
	ID2D1Factory* pD2DFactory;
	// WICλͼ����
	IWICImagingFactory* pIWICFactory;
	// Hwnd��� ������
	ID2D1HwndRenderTarget* pHWNDtarget;
	// DC���
	ID2D1DCRenderTarget* pDCtarget;
	// ���֡����Ҫ���ڻ�����ƹ���֡���ٻ���ʱ�������´���)
	map<string, SpriteFrame> frameStorge;

public:
	FrameHandler();
	void SetWindowHand(HWND, SIZE);
	// ����λͼ
	ID2D1Bitmap* CreateBitmapFromFile(LPCWSTR fileName);
	void NextFrame();


};
