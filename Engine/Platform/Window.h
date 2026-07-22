#pragma once 

class Window
{
    public:
       virtual ~Window() = default;

       virtual bool Create() = 0;
       virtual void Update() = 0;
       virtual void Destroy() = 0;
};