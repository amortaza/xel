#include "stdafx.h"

#include "WinOs/WinOs.h"

#include "Xel/Xel_WndProc.h"
#include "Xel/Xel_Mouse.h"
#include "Xel/Xel_Keyboard.h"
#include "Xel/Xel_Window.h"

#ifndef GET_XBUTTON_WPARAM
#   define GET_XBUTTON_WPARAM(w) (HIWORD(w))
#endif

namespace xel {
    namespace _ {

        void handleResize(int w, int h) {

            if (window::_::g_resizeCount > 0) {

                window::width = w;
                window::height = h;

                glViewport(0, 0, w, h);

                if (window::_::g_onResize)
                    window::_::g_onResize(w, h);
            }

            ++window::_::g_resizeCount;
        }

        bool isMouseMsg(UINT msg) {
            return msg == WM_MOUSEMOVE
                    || msg == WM_LBUTTONDOWN
                    || msg == WM_LBUTTONUP
                    || msg == WM_RBUTTONDOWN
                    || msg == WM_RBUTTONUP
                    || msg == WM_MBUTTONDOWN
                    || msg == WM_MBUTTONUP
                    || msg == WM_XBUTTONDOWN
                    || msg == WM_XBUTTONUP
                    || msg == WM_MOUSEWHEEL;
        }

        void handleMouseEvent(UINT msg, WPARAM wParam, LPARAM lParam) {
            int x = GET_X_LPARAM(lParam);
            int y = GET_Y_LPARAM(lParam);

            if (msg == WM_MOUSEMOVE)
                mouse::_::g_onMove(x, y);

            else if (msg == WM_LBUTTONDOWN)
                mouse::_::g_onButton(mouse::Left, mouse::Action::Down, x, y);

            else if (msg == WM_LBUTTONUP)
                mouse::_::g_onButton(mouse::Left, mouse::Action::Up, x, y);

            else if (msg == WM_RBUTTONDOWN)
                mouse::_::g_onButton(mouse::Right, mouse::Action::Down, x, y);

            else if (msg == WM_RBUTTONUP)
                mouse::_::g_onButton(mouse::Right, mouse::Action::Up, x, y);

            else if (msg == WM_MBUTTONDOWN)
                mouse::_::g_onButton(mouse::Middle, mouse::Action::Down, x, y);

            else if (msg == WM_MBUTTONUP)
                mouse::_::g_onButton(mouse::Middle, mouse::Action::Up, x, y);

            else if (msg == WM_XBUTTONDOWN) {
                int xbutton = GET_XBUTTON_WPARAM (wParam);

                if (xbutton == XBUTTON1)
                    mouse::_::g_onButton(mouse::X1, mouse::Action::Down, x, y);

                else if (xbutton == XBUTTON2)
                    mouse::_::g_onButton(mouse::X2, mouse::Action::Down, x, y);
            }

            else if (msg == WM_XBUTTONUP) {
                int xbutton = GET_XBUTTON_WPARAM (wParam);

                if (xbutton == XBUTTON1)
                    mouse::_::g_onButton(mouse::X1, mouse::Action::Up, x, y);

                else if (xbutton == XBUTTON2)
                    mouse::_::g_onButton(mouse::X2, mouse::Action::Up, x, y);
            }

            else if (msg == WM_MOUSEWHEEL)
                mouse::_::g_onScroll(GET_WHEEL_DELTA_WPARAM(wParam));
        }

        void HandleKeyboardEvent(UINT msg, WPARAM wParam, LPARAM lParam) {
            unsigned long long  previousState = lParam & 0x40000000;

            if (msg == WM_KEYDOWN && previousState == 0 /* up */ )
                keyboard::_::g_onDown(xel::keyboard::_::virtualCodeToXCode(wParam));

            else if (msg == WM_KEYUP )
                keyboard::_::g_onUp(xel::keyboard::_::virtualCodeToXCode(wParam));
        }
    }

    LRESULT CALLBACK _WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

        if (_::isMouseMsg(msg))
            _::handleMouseEvent(msg, wParam, lParam);
        
        else if (msg == WM_KEYDOWN || msg == WM_KEYUP)
            _::HandleKeyboardEvent(msg, wParam, lParam);

        else if (msg == WM_SIZE)
            _::handleResize(LOWORD(lParam), HIWORD(lParam));

        else if (msg == WM_CREATE) {
            win32::gl::createGLContext(hwnd);
            glewInit();

			printf("OpenGL/GLEW context created\n");
        }

        else if (msg == WM_CLOSE) {
            xel::window::_::g_onBeforeGLDeleted();

            win32::gl::deleteGLContext(hwnd);
        }

        else if (msg == WM_DESTROY)
            PostQuitMessage(0);

        else
            return DefWindowProc(hwnd, msg, wParam, lParam);

        return 0;
    }
}

