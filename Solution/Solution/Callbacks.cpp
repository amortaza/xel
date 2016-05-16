#include "stdafx.h" 

void OnMouseMove(int x, int y) {
}

void OnMouseButton(Xel::Mouse::Button button, Xel::Mouse::Action action, int x, int y) {
}

void OnMouseScroll(int amount) {
}

void OnKeyDown(unsigned long long xcode) {
	Xel::Quit();
}

void OnKeyUp(unsigned long long xcode) {
}

void OnResize(int width, int height) {
    glViewport(0, 0, width, height);

	printf("Set glViewport in OnResize\n");

}
