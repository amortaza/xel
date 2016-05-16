#pragma once

namespace xel {
    namespace mouse {

        enum Button {
            Left, Right, Middle, X1, X2
        };

        enum Action {
            Down, Up
        };

        namespace _ {
            extern void (*g_onMove)(int x, int y);
            extern void (*g_onButton)(Button button, Action action, int x, int y);
            extern void (*g_onScroll)(int amount);
        }

        void setCallbacks(  void (*OnMove)(int x, int y),
                            void (*OnButton)(mouse::Button button, mouse::Action action, int x, int y),
                            void (*OnScroll)(int amount));
    }
}