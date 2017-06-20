#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include "../TrafficEngine/TrafficSettings.h"
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib,"../TrafficEngine.lib")
#define TRAFFICFVF (D3DFVF_XYZ|D3DFVF_DIFFUSE | D3DFVF_TEX1)
#pragma once
namespace Traffic {
	class TrafficVertex
	{
	public:
		FLOAT X, Y, Z;
		D3DCOLOR COLOR;
		FLOAT U, V;
	};
}
