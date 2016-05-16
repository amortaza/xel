#pragma once

namespace xel {

    namespace keyboard {

        namespace _ {
            extern void (*g_onDown)(unsigned long long xcode);
            extern void (*g_onUp)(unsigned long long xcode);

            unsigned long long virtualCodeToXCode(unsigned long long vcode);
        }

        void setCallbacks(  void (*OnDown)(unsigned long long xcode),
                            void (*OnUp)(unsigned long long xcode));

        char* xCodeToString(unsigned long long xcode);
    }
}