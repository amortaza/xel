#include "stdafx.h"

#include "xel/xel.h"

void OnMouseMove(int x, int y) {
}

void OnMouseButton(xel::mouse::Button button, xel::mouse::Action action, int x, int y) {
}

void OnMouseScroll(int amount) {
}

void OnKeyDown(unsigned long long xcode) {
	xel::quit();
}

void OnKeyUp(unsigned long long xcode) {
}

void OnResize(int width, int height) {
	glViewport(0, 0, width, height);

	printf("Set glViewport in OnResize\n");

}

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

