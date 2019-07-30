//
//	main.h
//
//					Author:Yu Nishimaki	Date:yyyy/mm/dd
//-----------------------------------------------------
//	�ύX�_
//	Date:yyyy/mm/dd
//
//=====================================================

//=====================================================
//	�C���N���[�h�K�[�h
//=====================================================
#ifndef MAIN_H
#define MAIN_H


//=====================================================
//	�C���N���[�h	include
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
//	�}�N���錾		define
//=====================================================
#define SCREEN_WIDTH	(1280)
#define SCREEN_HEIGHT	(720)

#define CLASS_NAME		("DX9AppClass")
#define WINDOW_NAME		("IronFlower")
#define WINDOW_STYLE	(WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME)


//=====================================================
//	�v���g�^�C�v�錾
//=====================================================
HWND GetWindow();
HINSTANCE GetInstance();




#endif // !MAIN_H