#include "stdafx.h"

#include "WinOs/WinOs.h"

#include "Xel/Xel_WndProc.h"
#include "Xel/Xel_Window.h"

namespace xel {

    void init() {
        win32::window::createMainWindow(_WndProc);
    }

	void swap() {
		win32::window::swapBuffers();
	}

    void quit() {
        win32::window::close();
    }

    void loop(void (*tickCallback)() ) {
        MSG msg;

        while (true) {
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) == TRUE) {
                if (msg.message == WM_QUIT) 
					return;

                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            // Resize must have been called once
            if (window::_::g_resizeCount > 0) 
				tickCallback();
        }
    }
}
