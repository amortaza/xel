#pragma once

namespace xel {
    namespace window {

        extern int width, height;

        void setPosition(int x, int y);

        void setSize(int w, int h);

        void setTitle(char *title);

        void setCallbacks(
                void (*OnResize)(int w, int h),
                void (*OnAfterGLCreated)(),
                void(*OnBeforeGLDeleted)()
        );

        namespace _ {
            extern unsigned int g_resizeCount;
            extern void (*g_onResize)(int w, int h);
            extern void(*g_onBeforeGLDeleted)();
        }
    }
}