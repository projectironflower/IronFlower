//
//	main.h
//
//					Author:Yu Nishimaki	Date:yyyy/mm/dd
//-----------------------------------------------------
//	変更点
//	Date:yyyy/mm/dd
//
//=====================================================

//=====================================================
//	インクルードガード
//=====================================================
#ifndef MAIN_H
#define MAIN_H


//=====================================================
//	インクルード	include
//=====================================================
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <assert.h>

#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "d3d9.lib")
#ifdef _DEBUG	
#pragma comment (lib, "d3dx9d.lib")
#else
#pragma comment (lib, "d3dx9.lib")
#endif
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")


//=====================================================
//	マクロ宣言		define
//=====================================================
#define SCREEN_WIDTH	(1280)
#define SCREEN_HEIGHT	(720)

#define CLASS_NAME		("DX9AppClass")
#define WINDOW_NAME		("IronFlower")
#define WINDOW_STYLE	(WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME)


//=====================================================
//	プロトタイプ宣言
//=====================================================
HWND GetWindow();
HINSTANCE GetInstance();




#endif // !MAIN_H