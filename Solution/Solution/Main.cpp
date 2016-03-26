#include "stdafx.h"

#include "Callback.h"

void Init() {
}

void Uninit() {
}

void OnTick() {

    Xel::Swap();
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

