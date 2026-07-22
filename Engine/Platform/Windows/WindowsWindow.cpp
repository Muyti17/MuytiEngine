#include "WindowsWindow.h"
#include "../../Core/include/Logger.h"
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool WindowsWindow::Create()
{
    WNDCLASS wc{};
    wc.lpszClassName = L"MuytiWindow";
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);

    if (!RegisterClass(&wc))
    { 
        Logger::Error("Failed to register window class.");
        return false;
    }

    m_Window = CreateWindowEx(
        0,                      // Extra stil
        L"MuytiWindow",         // Sınıf adı
        L"Muyti Engine",        // Başlık
        WS_OVERLAPPEDWINDOW,    // Stil
        CW_USEDEFAULT,          // X konumu
        CW_USEDEFAULT,          // Y konumu
        1280,                   // Genişlik
        720,                    // Yükseklik 
        nullptr,                // Ana pencere (parent)
        nullptr,                // Menü
        wc.hInstance,           // Uygulama instance'ı
        nullptr                 // Ek kullanıcı verisi
    );

    if (!m_Window)
    {
        Logger::Error("Failed to create window.");
        return false;
    }

    ShowWindow(m_Window, SW_SHOW); // Pencereyi görünür yap.
    UpdateWindow(m_Window); // İlk çizimini yap.

    Logger::Info("Creating Windows window");

    return true;
}

void WindowsWindow::Update()
{
    Logger::Info("Updating Windows window");
}

void WindowsWindow::Destroy()
{
    Logger::Info("Destroying Windows window");
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, msg, wParam, lParam);
}