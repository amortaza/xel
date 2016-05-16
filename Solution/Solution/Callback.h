#pragma once

void OnMouseMove(int x, int y);
void OnMouseButton(xel::mouse::Button button, xel::mouse::Action action, int x, int y);
void OnMouseScroll(int amount);

void OnKeyDown(unsigned long long xcode);
void OnKeyUp(unsigned long long xcode);
void OnResize(int w, int h);

