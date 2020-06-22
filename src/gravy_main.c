#include <windows.h>
#include "./utils/language_layer.h"

static bool running;

LRESULT CALLBACK WindowCallback(HWND   window,
                                UINT   message,
                                WPARAM wParam,
                                LPARAM lParam)
{
    LRESULT result;
    
    switch (message){
        case WM_QUIT:
        {
            running = false;
        } break;
        
        case WM_SIZE:
        {
            OutputDebugStringA("WM_SIZE");
        } break;
        
        default:
        {
            result = 0;
        } break;
    }
    
    return result;
}

INT WinMain(HINSTANCE hInstance, 
            HINSTANCE hPrevInstance, 
            PSTR CommandLine,
            INT CommandLineShow)
{
    
    LPCSTR className = "PhysicsEngineWindow";
    LPCSTR gameName = "Gravy Engine";
    WNDCLASS windowClass = {0};
    
    windowClass.style = CS_VREDRAW | CS_HREDRAW;
    windowClass.lpfnWndProc = WindowCallback;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = className;
    return 0;
}