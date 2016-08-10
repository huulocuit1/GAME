#include "MarioGame.h"



MarioGame::MarioGame()
{
	d3d = NULL;
	d3ddv = NULL;
	backBuffer = NULL;	
}

MarioGame* MarioGame::instances = NULL;


MarioGame*MarioGame::getInstance()
{
	if (instances == NULL)
	{
		instances = new MarioGame();
	}
	return instances;
}
LRESULT CALLBACK MarioGame::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
void MarioGame::initWindow()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc =(WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = name;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);
	hWnd =
		CreateWindow(
			name,
			name,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
}
void MarioGame::initDirectX()
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = BUFFER_HEIGHT;
	d3dpp.BackBufferWidth =BUFFER_WIDTH;

	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv);

	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

}
void MarioGame::initVariables()
{
	keyboard = new FKeyboard(hInstance, hWnd);
	vpx = 0;
	vpy = VIEW_PORTY;
}
void MarioGame::initGame(HINSTANCE hinstance, LPWSTR name, int frame_rate)
{
			
	this->frame_rate = frame_rate;
	this->name = name;
	hInstance = hinstance;
	initWindow();
	initDirectX();
	initVariables();
	this->player = new Player(d3ddv, 100.0f, 250.0f);//268
	
	///new objects
	
	state = new StateMap();
	if (currentstate == 1)
	{
		state = &state_map1;
	}
	else if (currentstate == 2)
	{
		state = &state_map2;
	}
	
	state->initState(d3ddv, keyboard,player);
}
void MarioGame::viewportUpdate()
{
	if (vpx < 0) vpx = 0;
	if (vpx+BUFFER_WIDTH/2>= MAX_MAP1-1000)
	vpx = MAX_MAP1 - BUFFER_WIDTH/2;
	if (vpy + SCREEN_HEIGHT >= MAP1_TILE_SIZE_HEIGHT)
	{
	vpy = MAP1_TILE_SIZE_HEIGHT - SCREEN_HEIGHT;
	}

	
}
void MarioGame::updateGame(float time)
{
	if (changelevel == 1)
	{
	
		state = &state_map2;
		state->initState(d3ddv, keyboard,player);
		changelevel = 0;
	}
	if (player->getNumberLive() <3)
	{
		if (player->getReset() == true)
		{
			
			state->initState(d3ddv, keyboard, player);
			player->setReset(false);
		}
	}
	else if (player->getNumberLive()>3)
	{
		CloseWindow(hWnd);
	}
	state->updateState(vpx, vpy, time);
	
 }
void MarioGame::renderGame()
{
	if (d3ddv->BeginScene())
	{
		d3ddv->ColorFill(backBuffer, NULL, 150);
		
		state->renderState(vpx, vpy);
		d3ddv->EndScene();
	}
	d3ddv->Present(NULL, NULL, NULL, NULL);
}
void MarioGame::runGame()
{

	MSG msg;
	int done = 0;
	DWORD frame_start = GetTickCount();
	float gameTime = 0.0f;
	float frame_rate = 1000.0f /60;

	while (!done)
	{
		static DWORD start = GetTickCount();
		static DWORD stop;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		keyboard->updateKeyboard();
		stop = GetTickCount();
		auto gameTime = stop - start;
		start = stop;
		updateGame(gameTime);
		renderGame();
		auto sleepTime = frame_rate - (GetTickCount() - stop);
		if (sleepTime > 0)
		{
			SleepEx(sleepTime, false);
		}

	}
}
void MarioGame::isxit()
{

	SAFE_RELEASE(d3d);
	SAFE_RELEASE(d3ddv);
	
}
MarioGame::~MarioGame()
{


}
