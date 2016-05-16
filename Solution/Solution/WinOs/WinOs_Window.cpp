#include "stdafx.h"

#include "WinOs.h"

namespace win32 {
    namespace _ {

        void registerWindowClass(WNDPROC wndProc) {
            WNDCLASSEX wc;

            wc.cbSize        = sizeof(WNDCLASSEX);
            wc.style         = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
            wc.lpfnWndProc   = wndProc;
            wc.cbClsExtra    = 0;
            wc.cbWndExtra    = 0;
            wc.hInstance     = GetModuleHandle(0);
            wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
            wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
            wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
            wc.lpszMenuName  = NULL;
            wc.lpszClassName = "AceWindowClass";
            wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

            if (!RegisterClassEx(&wc))
                throw "Failed to register window class.";
        }

        HWND createMainWindowEx() {
            HWND hwnd = CreateWindowEx(
                    WS_EX_CLIENTEDGE,
                    "AceWindowClass",
                    "The title of my window",
                    WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    800,
                    600,
                    NULL,
                    NULL,
                    GetModuleHandle(0),
                    NULL);

            if (hwnd == NULL)
                throw "Could not create window handle.";

            return hwnd;
        }
    }

    namespace window {

        HWND g_hwnd;

        void createMainWindow(WNDPROC wndProc) {
            _::registerWindowClass(wndProc);

            g_hwnd = _::createMainWindowEx();

            ShowWindow(g_hwnd, SW_SHOW);
            UpdateWindow(g_hwnd);
        }

        void swapBuffers() {
            SwapBuffers(gl::g_hdc);
        }

        void setPosition(int left, int top) {
            SetWindowPos(g_hwnd, 0, left, top, -1, -1, SWP_NOZORDER | SWP_NOSIZE | SWP_SHOWWINDOW);
        }

        void setSize(int width, int height) {
            SetWindowPos(g_hwnd, 0, -1, -1, width, height, SWP_NOZORDER | SWP_NOMOVE | SWP_SHOWWINDOW);
        }

        void setTitle(char* title) {
            SetWindowText(g_hwnd, title);
        }

        void close() {
            PostMessage(window::g_hwnd, WM_CLOSE, 0, 0);
        }
    }
}