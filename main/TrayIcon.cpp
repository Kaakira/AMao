#include "TrayIcon.h"

TrayIcon::TrayIcon(HWND wnd, HICON ntfIcon)
{

	trayIcon = { 0 };
	trayIcon.hWnd = wnd;
	trayIcon.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	trayIcon.cbSize = sizeof(NOTIFYICONDATA);
	trayIcon.uCallbackMessage = AMAOMSG_NOTIFYICON;
	trayIcon.uID = AMAO_TRAYICON_ID;
	trayIcon.hIcon = ntfIcon;
	lstrcpy(trayIcon.szTip, L"=���أ�=");
}

void TrayIcon::AddNotifyIcon()
{
	Shell_NotifyIcon(NIM_ADD, &trayIcon);
}

