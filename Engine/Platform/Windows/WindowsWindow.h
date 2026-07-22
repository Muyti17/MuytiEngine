#pragma once

#include "../Window.h"

#include <Windows.h>

class WindowsWindow : public Window
{
    public:
        bool Create() override;
        void Update() override;
        void Destroy() override;

    private:
        HWND m_Window = nullptr;
};