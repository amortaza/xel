#include "stdafx.h" 

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
