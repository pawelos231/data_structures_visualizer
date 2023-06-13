#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include "raylib.h"
#include "raygui.h";
#include <iostream>
#include "./window.h"



void InitializeWindow() {


	const char* STRUCTURES[] = {
	"Linked list",
	"Stack",
	"Queue",
	"Disjoint set",
	"BST",
	"AVL",
	"BIT",
	"PAT",
	"Trie",
	"k-d tree"
	};


	const int screenWidth = 1280;
	const int screenHeight = 720;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(60);
	InitWindow(screenWidth, screenHeight, "Data Structure Visualiser");

	Rectangle leftPanel = Rectangle{ 2,2,0,0 };
	Rectangle propPanel;
	Rectangle viewPanel;

	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
	GuiSetStyle(DEFAULT, TEXT_PADDING, 20);

	while (!WindowShouldClose())
	{
		leftPanel.width = std::max(GetScreenWidth() / 5, 300);
		leftPanel.height = GetScreenHeight() - 2;

		BeginDrawing();
		ClearBackground(RAYWHITE);

		GuiPanel(leftPanel, "Data structures");

		Rectangle start = { leftPanel.x + 10, leftPanel.y + 30, leftPanel.width - 20, 30 };
		for (auto structure : STRUCTURES) {
			GuiButton(start, structure);
			start.y += 32;
		}

		propPanel = leftPanel;
		propPanel.y = start.y + 10;
		propPanel.height -= propPanel.y - 2;
		GuiPanel(propPanel, "Inspector");

		viewPanel = leftPanel;
		viewPanel.x += viewPanel.width + 2;
		viewPanel.width = GetScreenWidth() - viewPanel.x - 2;
		GuiPanel(viewPanel, "Structure viewer");

		GuiDrawText("No structure works yet qwq...\n", viewPanel, TEXT_ALIGN_CENTER, DARKGRAY);
		GuiDrawText("\nCome back later...", viewPanel, TEXT_ALIGN_CENTER, GRAY);

		EndDrawing();
	}

	CloseWindow();

}