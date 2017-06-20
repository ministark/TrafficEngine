#include "TrafficSprite.h"
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
		//Rendering
		void init(HWND hwnd);
		void beginRender();
		void endRender();
		void releaseRender();
		//Objects
		~TrafficRenderer();
	};
}
