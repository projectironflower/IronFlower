//
//	device_manager.h
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
#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H


//=====================================================
//	�C���N���[�h	include
//=====================================================


//=====================================================
//	�}�N���錾		define
//=====================================================


//=====================================================
//	�O���[�o���ϐ��錾		global
//=====================================================


//=====================================================
//	�񋓌^�錾		enum
//=====================================================


//=====================================================
//	�\���̐錾		struct
//=====================================================


//=====================================================
//	CDeviceManager�N���X		class
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