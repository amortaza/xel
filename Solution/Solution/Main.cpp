#include "stdafx.h"

#include "Callback.h"

void Init() {
}

void Uninit() {
}

void OnTick() {

    xel::swap();
}

int main(int argc, char** argv) {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    xel::init();

    xel::window::setCallbacks(OnResize, Init, Uninit);

    xel::mouse::setCallbacks(
        OnMouseMove,
        OnMouseButton,
        OnMouseScroll);

    xel::keyboard::setCallbacks(
        OnKeyDown,
        OnKeyUp);

    xel::window::setTitle("Xel v2016.03.26");
    xel::window::setPosition(200, 100);
    xel::window::setSize(1280, 800);

    xel::loop(OnTick);

	//int i;std::cin >> i;

	printf("Good bye.\n");
	return 0;
}

