#include "raylib.h"
#include "structures/linked_list.h"
#include <iostream>

void draw_centered(const char* text, int height, int fontSize) {
	int width = MeasureText(text, fontSize);
	DrawText(text, (GetScreenWidth() - width) / 2, height, fontSize, DARKGRAY);
}

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Data Structure Visualiser");
	SetTargetFPS(60);

	Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		draw_centered("Data Structure Visualiser", 20, 25);
		draw_centered("Pawel Wilk", 45, 20);

		EndDrawing();
	}

	CloseWindow();

	return 0;
	return 0;
}