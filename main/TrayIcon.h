#pragma once
#include <Windows.h>

// ����ͼ��
#define AMAOMSG_NOTIFYICON 0x00101
#define AMAO_TRAYICON_ID  0x00110
#define NOTIFYICONUID 0x000110
// ���̲˵����˳�
#define NTI_QUIT 0
// ���̲˵������߲���
#define NTI_ABM 0x000233

class TrayIcon
{
private:
public:
	NOTIFYICONDATA trayIcon;
	TrayIcon(HWND wnd);

	void AddNotifyIcon();
};

