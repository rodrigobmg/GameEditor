#pragma once

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <d3d11.h>
#include <directxmath.h>
#include <memory>
#include <string>

using namespace DirectX;

class D3DConfigurer
{
private:
  bool m_vsync_enabled;
  int m_videoCardMemorySize;
  std::wstring m_videoCardDescription;
  IDXGISwapChain* m_swapChain;
  ID3D11Device* m_device;
  ID3D11DeviceContext* m_deviceContext;
  ID3D11RenderTargetView* m_renderTargetView;
  ID3D11Texture2D* m_depthStencilBuffer;
  ID3D11DepthStencilState* m_depthStencilState;
  ID3D11DepthStencilView* m_depthStencilView;
  ID3D11RasterizerState* m_rasterState;
  ID3D11DepthStencilState* m_depthDisabledStencilState;
  ID3D11BlendState* m_alphaEnableBlendingState;
  ID3D11BlendState* m_alphaDisableBlendingState;
public:
  D3DConfigurer();
  virtual ~D3DConfigurer();

  bool Initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen);
  void Shutdown();

  ID3D11Device* GetDevice();
  ID3D11DeviceContext* GetDeviceContext();

  void BeginScene(float, float, float, float);
  void EndScene();

  const std::wstring& GetVideoCardInfo();

  void TurnZBufferOn();
  void TurnZBufferOff();

  void TurnOnAlphaBlending();
  void TurnOffAlphaBlending();

};

