#pragma once
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <vector>
#include <dxgi.h>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "windowscodecs.lib")

using namespace std;



// ������ϵ��ͼƬ�����Ź�����
class SpriteAnimation
{
public:
	SpriteAnimation(HDC* hdcSrc, RECT* rcClient);
	~SpriteAnimation();

	// ��ȡ��ǰʱ�� ms��λ
	float GetCurrentTick();
	// ���Ŷ���
	bool Play(ID2D1Bitmap* images, float delay);
	// �ϴβ������ʱ��
	float lastPlayTick;
};



