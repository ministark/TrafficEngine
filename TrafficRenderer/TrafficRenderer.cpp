#include "TrafficRenderer.h"
using namespace Traffic;


TrafficRenderer::TrafficRenderer()
{
}

void TrafficRenderer::init(HWND hwnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hwnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = TrafficSettings::SCREEN_WIDTH; d3dpp.BackBufferHeight = TrafficSettings::SCREEN_HEIGHT;

	// create a device class using this information and the info from the d3dpp stuct
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
	d3ddev->SetRenderState(D3DRS_LIGHTING, FALSE);
}

void Traffic::TrafficRenderer::beginRender()
{
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	d3ddev->BeginScene();

	// Setting the Camera
	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView,
		&D3DXVECTOR3(TrafficSettings::CAMERA_POSX, TrafficSettings::CAMERA_POSY, TrafficSettings::CAMERA_POSZ),    // the camera position
		&D3DXVECTOR3(TrafficSettings::CAMERA_FACEX, TrafficSettings::CAMERA_FACEY, TrafficSettings::CAMERA_FACEZ),    // the look-at position
		&D3DXVECTOR3(TrafficSettings::CAMERA_UPX, TrafficSettings::CAMERA_UPY, TrafficSettings::CAMERA_POSZ));    // the up direction
	d3ddev->SetTransform(D3DTS_VIEW, &matView);    // set the view transform to matView

	// Setting Orthogonal Projection
	D3DXMATRIX matProj;
	D3DXMatrixOrthoLH(&matProj, TrafficSettings::SCREEN_WIDTH, TrafficSettings::SCREEN_HEIGHT, 1.0f, 100.0f);
	d3ddev->SetTransform(D3DTS_PROJECTION, &matProj);
}

void Traffic::TrafficRenderer::endRender()
{
	// End Scene
	d3ddev->EndScene();
	d3ddev->Present(NULL, NULL, NULL, NULL);
}

void Traffic::TrafficRenderer::releaseRender()
{
	d3ddev->Release();
	// Release the Direct3D
	d3d->Release();
}


TrafficRenderer::~TrafficRenderer()
{
}
