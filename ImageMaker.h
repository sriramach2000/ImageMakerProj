#pragma once
#include <iostream>
const int MAX_WIDTH = 640;
const int MAX_HEIGHT = 480;
const int MAX_COLOR = 255;
enum COLOR { RED, GREEN, BLUE };
using namespace std;

class ImageMaker
{
public:
	ImageMaker();
	ImageMaker(string filename);
	// Opens image with filename and stores information into
	void LoadImage(string filename);
	void SaveImage(string filename);
	
	// Size functions
	int GetWidth();
	int GetHeight();
	void SetWidth(int width);
	void SetHeight(int height);
	
	// Color functions
	int GetPenRed();
	int GetPenGreen();
	int GetPenBlue();
	void SetPenRed(int newR);
	void SetPenGreen(int newG);
	void SetPenBlue(int newB);
	
	// Drawing methods
	// These methods will use the current red, green, blue values of the pen
	void DrawPixel(int x, int y);
	void DrawRectangle(int x1, int y1, int x2, int y2);
	void DrawLine(int x1, int y1, int x2, int y2);

private:
	int width;
	int height;
	int pen_red; // Used by draw functions
	int pen_green; // Used by draw functions
	int pen_blue; // Used by draw functions
	short image[MAX_WIDTH][MAX_HEIGHT][3];
	
};

