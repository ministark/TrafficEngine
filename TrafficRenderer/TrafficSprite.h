#include "TrafficVertex.h"
#pragma once

namespace Traffic {
	class TrafficSprite
	{
		LPDIRECT3DDEVICE9 d3ddev;
	public:
		short indices[6] = { 0,1,2,1,3,2 };
		TrafficVertex vertices[4];

		LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;
		LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;
		IDirect3DTexture9 *g_texture = NULL;

		TrafficSprite(LPDIRECT3DDEVICE9, float, float, std::string);
		TrafficSprite();

		void Render(float, float);
		void RenderX(float, float, float rx, float ry, float rz, float scalex, float scaley);
		~TrafficSprite();
	};
}
