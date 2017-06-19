#pragma once
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "../TrafficEngine/TrafficSettings.h"

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib,"../TrafficEngine.lib")

#pragma once
namespace Traffic {
	class TrafficRenderer
	{
		LPDIRECT3D9 d3d;								// the pointer to our Direct3D interface
		LPDIRECT3DDEVICE9 d3ddev;						// the pointer to the device class
		LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;		// the pointer to the vertex buffer
		IDirect3DTexture9 *g_texture = NULL;
	public:
		TrafficRenderer();
		void init(HWND hwnd);
		void beginRender();
		~TrafficRenderer();
	};
}
