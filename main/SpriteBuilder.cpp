#include "SpriteBuilder.h"


void SpriteBuilder::Configuration(HINSTANCE  hInstance)
{
	// TODO: �����ļ���ȡ���ã�Ŀǰд��
	int width = 128, height = 128, x = 500, y = 500;
	SpriteConfiguration config = {
		SIZE{width,height},
		POINT{x,y},
		hInstance
	};
	SpriteInstance::GetInstance()->Ready(config);


}


SpriteBuilder::SpriteBuilder()
{
}

SpriteBuilder::~SpriteBuilder()
{
}


void SpriteBuilder::Run()
{

	SpriteInstance::GetInstance()->Start();

	///// ����ͼ�� >>>
	//SpriteWindowTray trayIcon(wnd);
	//trayIcon.AddNotifyIcon();
	///// ����ͼ�� <<<

	//// ��ʾ����
	//ShowWindow(wnd, cmdShow);

	//MSG msg = { 0 };
	//while (msg.message != WM_QUIT)
	//{
	//	if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	//	{
	//		TranslateMessage(&msg);
	//		DispatchMessage(&msg);
	//	}
	//	mainWindow.RedrawWndFrame();
	//	// ���´�����Ϣ
	//	Sleep(DELAY_TIME);
	//}
	//// ����ͼ����ʧ
	//Shell_NotifyIcon(NIM_DELETE, mainWindow.trayIcon);
	//return static_cast<int>(msg.wParam);
}

