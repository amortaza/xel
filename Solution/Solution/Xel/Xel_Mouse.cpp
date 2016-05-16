#include "stdafx.h"

#include "Xel/Xel_Mouse.h"
#include "WinOs/WinOs.h"

namespace xel {
    namespace mouse {
        namespace _ {

            void (*g_onMove)(int x, int y);

            void (*g_onButton)(Button button, Action action, int x, int y);

            void (*g_onScroll)(int amount);
        }

        void setCallbacks(  void (*OnMove)(int x, int y),
                            void (*OnButton)(Button button, Action action, int x, int y),
                            void (*OnScroll)(int amount) ) {

            _::g_onMove      = OnMove;
            _::g_onButton    = OnButton;
            _::g_onScroll    = OnScroll;
        }
    }
}