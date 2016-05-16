#include "stdafx.h"

namespace win32 {

    namespace gl {

        HGLRC g_glrc;
        HDC   g_hdc;

        void createGLContext(HWND hwnd) {

            PIXELFORMATDESCRIPTOR pfd = {
                sizeof(PIXELFORMATDESCRIPTOR),                              // nSize
                1,                                                          // nVersion
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, // dwFlags
                PFD_TYPE_RGBA,                                              // iPixelType
                32,                                                         // cColorBits
                0, 0, 0, 0, 0, 0,
                0, 0,
                0,                  // AccumBits
                0, 0, 0, 0,
                32,                 // Depth
                8,                  // Stencil
                0,                  // Aux
                PFD_MAIN_PLANE,
                0,
                0, 0, 0
            };

            g_hdc = GetDC(hwnd); 

            int pixelFormat = ChoosePixelFormat(g_hdc, &pfd);

            SetPixelFormat(g_hdc, pixelFormat, &pfd);

            g_glrc = wglCreateContext(g_hdc);

            wglMakeCurrent (g_hdc, g_glrc);
        }

        void deleteGLContext(HWND hwnd) {            
			printf("Deleting GL RC Context\n");

            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(g_glrc);
            
			printf("Releacing DC\n");
            ReleaseDC(hwnd, g_hdc);

			printf("Destroying Window\n");
            DestroyWindow(hwnd);

			printf("Unregistring class\n");
            UnregisterClass("AceWindowClass", GetModuleHandle(0));
        }
    }
}