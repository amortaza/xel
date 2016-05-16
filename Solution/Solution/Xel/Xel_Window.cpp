#include "stdafx.h"

#include "xel-win32.h"
#include "Xel.h"

namespace xel {

    namespace window {

        int width, height;

        namespace _ {
            unsigned int g_resizeCount = 0;

            void (*g_onResize)(int w, int h) = 0;
            void (*g_onBeforeGLDeleted)() = 0;
        }

        void setPosition(int x, int y) {
            win32::window::setPosition(x, y);
        }

        void setSize(int w, int h) {
            if (_::g_onResize != 0)
                win32::window::setSize(w, h);

            else {                
				printf("Must call xel::window::SetCallbacks BEFORE calling SetSize.  Its just good manners :)\n");
                xel::quit();
            }
        }

        void setTitle(char *title) {
            win32::window::setTitle(title);
        }

        void setCallbacks(
                void (*OnResize)(int w, int h),
                void (*OnAfterGLCreated)(),
                void (*OnBeforeGLDeleted)() ) {

            _::g_onResize = OnResize;
            _::g_onBeforeGLDeleted = OnBeforeGLDeleted;

            OnAfterGLCreated();
        }
    }
}
