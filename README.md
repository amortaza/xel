# xel

Make sure to link to glew32s.lib;opengl32.lib;

Look at stdafx.h to see the basic includes

<pre><code>
#include "stdafx.h"

void Init() {
}

void Uninit() {
}

void OnTick() {

    Xel::Swap();
}

void OnMouseMove(int x, int y) {
}

void OnMouseButton(Xel::Mouse::Button button, Xel::Mouse::Action action, int x, int y) {
}

void OnMouseScroll(int amount) {
}

void OnKeyDown(unsigned long long xcode) {
}

void OnKeyUp(unsigned long long xcode) {
}

void OnResize(int w, int h) {
    glViewport(0, 0, w, h);

    std::cout << "Set glViewport" << std::endl;

}

int main(int argc, char** argv) {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Xel::Init();

    Xel::Window::SetCallbacks(OnResize, Init, Uninit);

    Xel::Mouse::SetCallbacks(
        OnMouseMove,
        OnMouseButton,
        OnMouseScroll);

    Xel::Keyboard::SetCallbacks(
        OnKeyDown,
        OnKeyUp);

    Xel::Window::SetTitle("Xel v2016.03.26");
    Xel::Window::SetPosition(200, 100);
    Xel::Window::SetSize(1280, 800);

    Xel::Loop(OnTick);

    std::cout << "good bye." << std::endl;	return 0;
}


</code></pre>