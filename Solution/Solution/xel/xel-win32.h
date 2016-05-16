#pragma once

namespace win32 {

    namespace _ {

        void registerWindowClass(WNDPROC wndProc);

        HWND createMainWindowEx();
    }

    namespace window {
        extern HWND g_hwnd;

        void createMainWindow(WNDPROC wndProc);

        void swapBuffers();

        void setPosition(int left, int top);

        void setSize(int width, int height);

        void setTitle(char* title);

        void close();
    }
}

namespace win32 {

    namespace gl {

        extern HGLRC g_glrc;
        extern HDC   g_hdc;

        void createGLContext(HWND hwnd);
        void deleteGLContext(HWND hwnd);
    }
}
