#include "SpriteWindow.h"
#include "SpriteWndProc.h"


SpriteWindow::SpriteWindow(LPCSTR className, HINSTANCE hInstance, LPCSTR wndTitle, SIZE wndsize)
	:windowClassName(className), instance(hInstance), windowTitle(wndTitle), windowSize(wndsize) {
}

SpriteWindow::~SpriteWindow()
{
}
//
HWND SpriteWindow::CreateIrrWindow(POINT point) {

	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = SpriteWndProc;
	wndClass.hInstance = this->instance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = this->windowClassName;

	// ע��
	RegisterClassEx(&wndClass);
	// ����
	this->window = CreateWindowEx(
		// ������չ��ʽ
		WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_LAYERED,
		// ��������
		this->windowClassName,
		// ���ڱ���
		this->windowTitle,
		// ������ʽ
		WS_POPUP | WS_VISIBLE,
		// ���ڳ�ʼ��ĻX����
		point.x,
		// ���ڳ�ʼ��ĻY����
		point.y,
		// ���ڳ�ʼ���
		this->windowSize.cx,
		// ���ڳ�ʼ�߶�
		this->windowSize.cx,
		// ��������
		NULL,
		// �˵��ľ�������Ӵ��ڵı�ʶ��
		NULL,
		// Ӧ�ó���ʵ���ľ��
		this->instance,
		// ָ�򴰿ڵĴ�������
		this
	);

	/// ��ʼ��hdc  ��������dc >>>
	RECT clientRect = { 0,0,this->windowSize.cx,this->windowSize.cy };
	this->hdcDst = GetDC(this->window);
	this->hdcSrc = CreateCompatibleDC(this->hdcDst);
	HBITMAP memBitmap = ::CreateCompatibleBitmap(hdcDst, this->windowSize.cx, this->windowSize.cy);
	::SelectObject(this->hdcSrc, memBitmap);

	return this->window;
}

void SpriteWindow::RedrawWndFrame()
{
	POINT ptSrc = { 0 };
	BLENDFUNCTION bf;
	bf.AlphaFormat = AC_SRC_ALPHA;
	bf.BlendFlags = 0;
	bf.BlendOp = AC_SRC_OVER;
	bf.SourceConstantAlpha = 255;
	::UpdateLayeredWindow(this->window, this->hdcDst, NULL, &this->windowSize, this->hdcSrc, &ptSrc, NULL, &bf, ULW_ALPHA);
}


int WINAPI WinMain(_In_ HINSTANCE  hInstance, _In_opt_ HINSTANCE prevInstance, _In_ char* lpCmdLine, _In_ int cmdShow)
{

	// ����Ĭ�ϲ��� 
	int width = 128, height = 128, x = 500, y = 500;

	// ���첢����windows������Ϣ
	SpriteWindow mainWindow("AMao-main", hInstance, "AMao Title", SIZE{ width,height });
	HWND wnd = mainWindow.CreateIrrWindow(POINT{ x, y });

	/// ����ͼ�� >>>
	SpriteWindowTray trayIcon(wnd);
	trayIcon.AddNotifyIcon();
	/// ����ͼ�� <<<

	// ��ʾ����
	ShowWindow(wnd, cmdShow);

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		mainWindow.RedrawWndFrame();
		// ���´�����Ϣ
		Sleep(DELAY_TIME);
	}
	// ����ͼ����ʧ
	// Shell_NotifyIcon(NIM_DELETE, mainWindow.trayIcon);
	return static_cast<int>(msg.wParam);
}

