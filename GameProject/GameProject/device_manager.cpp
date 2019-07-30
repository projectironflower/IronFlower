//
//	device_manager.cpp
//
//					Author:Yu Nishimaki	Date:yyyy/mm/dd
//-----------------------------------------------------
//	変更点
//	Date:yyyy/mm/dd
//
//=====================================================

//=====================================================
//	インクルード	include
//=====================================================
#include "main.h"
#include "device_manager.h"


//=====================================================
//	マクロ宣言		define
//=====================================================


//=====================================================
//	列挙型宣言		enum
//=====================================================


//=====================================================
//	構造体宣言		struct
//=====================================================


//=====================================================
//	グローバル変数宣言		global
//=====================================================
static LPDIRECT3D9 g_pD3D = nullptr;
D3DPRESENT_PARAMETERS g_D3DPP = {};    // D3DDeviceの設定(現在)
bool g_bDeviceLost = false;      // デバイスの消失フラグ
bool g_bWindow = false;
SIZE g_WindowSize = {};

//=====================================================
//	CDeviceManagerクラス		class
//=====================================================

//-----------------------------------------------------
//	静的メンバの初期化
//-----------------------------------------------------
LPDIRECT3DDEVICE9		CDeviceManager::m_pDevice = nullptr;
D3DPRESENT_PARAMETERS	CDeviceManager::m_D3DPPCurrent = {};
D3DPRESENT_PARAMETERS	CDeviceManager::m_D3DPPWindow = {};
D3DPRESENT_PARAMETERS	CDeviceManager::m_D3DPPFullScreen = {};


//-----------------------------------------------------
//	初期化
//-----------------------------------------------------
void CDeviceManager::Initialize()
{
	g_WindowSize.cx = (LONG)GetSystemMetrics(SM_CXSCREEN);
	g_WindowSize.cy = (LONG)GetSystemMetrics(SM_CYSCREEN);

	// Direct3Dオブジェクトの作成
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	assert("Direct3Dオブジェクトの作成に失敗！" && g_pD3D);

	// D3DDeviceオブジェクトの設定(ウインドウ・モード用)
	m_D3DPPWindow.BackBufferWidth = SCREEN_WIDTH;
	m_D3DPPWindow.BackBufferHeight = SCREEN_HEIGHT;
	m_D3DPPWindow.BackBufferFormat = D3DFMT_UNKNOWN;
	m_D3DPPWindow.BackBufferCount = 1;
	m_D3DPPWindow.MultiSampleType = D3DMULTISAMPLE_NONE;
	m_D3DPPWindow.MultiSampleQuality = 0;
	m_D3DPPWindow.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_D3DPPWindow.hDeviceWindow = GetWindow();
	m_D3DPPWindow.Windowed = TRUE;
	m_D3DPPWindow.EnableAutoDepthStencil = FALSE;
	m_D3DPPWindow.AutoDepthStencilFormat = D3DFMT_A1R5G5B5;
	m_D3DPPWindow.Flags = 0;
	m_D3DPPWindow.FullScreen_RefreshRateInHz = 0;
	m_D3DPPWindow.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	// D3DDeviceオブジェクトの設定(フルスクリーン・モード)
	m_D3DPPFullScreen.BackBufferWidth = g_WindowSize.cx;
	m_D3DPPFullScreen.BackBufferHeight = g_WindowSize.cy;
	m_D3DPPFullScreen.BackBufferFormat = D3DFMT_X8R8G8B8;
	m_D3DPPFullScreen.BackBufferCount = 1;
	m_D3DPPFullScreen.MultiSampleType = D3DMULTISAMPLE_NONE;
	m_D3DPPFullScreen.MultiSampleQuality = 0;
	m_D3DPPFullScreen.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_D3DPPFullScreen.hDeviceWindow = GetWindow();
	m_D3DPPFullScreen.Windowed = FALSE;
	m_D3DPPFullScreen.EnableAutoDepthStencil = FALSE;
	m_D3DPPFullScreen.AutoDepthStencilFormat = D3DFMT_A1R5G5B5;
	m_D3DPPFullScreen.Flags = 0;
	m_D3DPPFullScreen.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	m_D3DPPFullScreen.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	// D3DDeviceオブジェクトの作成
	if (g_bWindow)
		m_D3DPPCurrent = m_D3DPPWindow;
	else
		m_D3DPPCurrent = m_D3DPPFullScreen;

	HRESULT hr = g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GetWindow(),
		D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_D3DPPCurrent, &m_pDevice);
	if (FAILED(hr))
	{
		assert(!"デバイスの作成に失敗！");
	}

	//// ビューポートの設定
	//D3DVIEWPORT9 vp;
	//vp.X = 0;
	//vp.Y = 0;
	//vp.Width = g_D3DPP.BackBufferWidth;
	//vp.Height = g_D3DPP.BackBufferHeight;
	//vp.MinZ = 0.0f;
	//vp.MaxZ = 1.0f;
	//hr = m_pDevice->SetViewport(&vp);
	//if (FAILED(hr))
	//	assert(!"ビューポートの設定に失敗！");

	// アルファブレンドの有効化
	m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	// 背景（すでに描かれた状態）DESTのブレンド設定
	m_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	// 今から描くポリゴン（SRC）のブレンド設定
	m_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);

	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	m_pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	m_pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	m_pDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

}


//-----------------------------------------------------
//	終了処理
//-----------------------------------------------------
void CDeviceManager::Finalize()
{
	if (m_pDevice)
	{
		m_pDevice->Release();
		m_pDevice = nullptr;
	}
}