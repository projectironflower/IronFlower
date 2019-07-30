//
//	device_manager.h
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
#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H


//=====================================================
//	インクルード	include
//=====================================================


//=====================================================
//	マクロ宣言		define
//=====================================================


//=====================================================
//	グローバル変数宣言		global
//=====================================================


//=====================================================
//	列挙型宣言		enum
//=====================================================


//=====================================================
//	構造体宣言		struct
//=====================================================


//=====================================================
//	CDeviceManagerクラス		class
//=====================================================

class CDeviceManager
{
private:
	static LPDIRECT3DDEVICE9 m_pDevice;
	static D3DPRESENT_PARAMETERS m_D3DPPCurrent;
	static D3DPRESENT_PARAMETERS m_D3DPPWindow;
	static D3DPRESENT_PARAMETERS m_D3DPPFullScreen;

public:
	static void Initialize();
	static void Finalize();
	static LPDIRECT3DDEVICE9 GetDevice() { return m_pDevice; }
	static D3DPRESENT_PARAMETERS GetPP() { return m_D3DPPCurrent; }
};



#endif // !CTEMPLATE_H