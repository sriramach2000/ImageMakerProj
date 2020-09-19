
#include "ImageMaker.h"
#include "string"
#include <fstream>
#include <cctype>
#include <cstring> 
using namespace std;

ImageMaker::ImageMaker()
{   
    SetHeight(MAX_HEIGHT);
    SetWidth(MAX_WIDTH);
    pen_red = MAX_COLOR;
    pen_green = MAX_COLOR;
    pen_blue = MAX_COLOR;
    for (int x = 0; x < MAX_WIDTH; x++) {
        for (int y = 0; y < MAX_HEIGHT; y++) {
            image[x][y][RED] = 0;
            image[x][y][GREEN] = 0;
            image[x][y][BLUE] = 0;
        }
    }
}

ImageMaker::ImageMaker(string filename)
{
    // Pre: File exists and is open
    //      File has the correct sequence of numbers


    // Post: makes structure of image for loading

    LoadImage(filename);
    pen_red = MAX_COLOR;
    pen_green = MAX_COLOR;
    pen_blue = MAX_COLOR;

}

void ImageMaker::LoadImage(string filename)
{
    // Pre: File exists and is open. The file has the right format

    // Post: loads the ppm image file to the image matrix 
    ifstream imgFile;
    string ppm_header;
    int height = 0;
    int width = 0;
    imgFile.open(filename.c_str());
    if (!imgFile) {
        cout << "file not found" << endl;
    }

    imgFile >> ppm_header;
    if (ppm_header != "P3") {
        cout << "not the right file" << endl;
        return;
    }
    
    imgFile >> width;
    if (width > MAX_WIDTH) {
        cout << "width too large!" << endl;
        exit(1);

    }
    SetWidth(width);


    imgFile >> height;
    
    if (height > MAX_HEIGHT) {
        cout << "height too large!" << endl;
        exit(1);
    }
    SetHeight(height);
    int max_color;

    imgFile >> max_color;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {

            for (int k = 0; k < 3; k++) {
                imgFile >> ImageMaker::image[i][j][k];

            }


        }
    }
    
    
}


void ImageMaker::SaveImage(string filename)
{
    // Pre: have an empty file opened and ready to be transfered 
    //      image is in a temporary location 

    // Post: Image is in a permanent location from where it can be accessed 
    ofstream imgFile;
    imgFile.open(filename.c_str());
    imgFile << "P3" << endl;
    imgFile << ImageMaker::width << " ";
    imgFile << ImageMaker::height << endl;
    imgFile << MAX_COLOR << endl;

    for (int i = 0; i < ImageMaker::height; i++) {
        for (int j = 0; j < ImageMaker::width; j++) {

            for (int k = 0; k < 3; k++) {
                imgFile << ImageMaker::image[i][j][k];
                imgFile << " ";
            }


        }
    }
    imgFile.close();
}

int ImageMaker::GetWidth()
{
    // Pre: setWidth is correct

    // Post: The width is successfully extracted 
    return width;
}

int ImageMaker::GetHeight()
{   //Pre: the hieght is correct in test file
    //post: correct heigh is extracted
    return height;
}

void ImageMaker::SetWidth(int width)
{
    
    // Pre: The driver program extracts the correct parameters for this method
    // Post: The getWidth function will get the correct number
    
      ImageMaker::width=width;
}

void ImageMaker::SetHeight(int height)
{
    //Pre: The height in driver file is set
    ImageMaker::height = height;
}

int ImageMaker::GetPenRed()
{
    // Pre: corresponding enumurated values are consistent
    return RED;
    // Post: implemented succesfully in printRGB command
}

int ImageMaker::GetPenGreen()
{
    // Pre: corresponding enumerated values are consistent 
    return GREEN;
    // Post: implemented succesfully in printRGB command
}

int ImageMaker::GetPenBlue()
{
    // Pre: corresponding enumerated values are consistent

    return BLUE;
    // Post: function returns the correct blue value
}

void ImageMaker::SetPenRed(int newR)
{
    //Pre: Using the enumerated Value in header file
    ImageMaker::pen_red = newR;
    // Post: setting the pen to red

}

void ImageMaker::SetPenGreen(int newG)
{
    //Pre: Using the enumerated Value in header file
    // Post: setting pen to green
    ImageMaker::pen_green = newG;

}

void ImageMaker::SetPenBlue(int newB)
{
    // Pre: Using the enumerated Value in header file 
    // Post: setting pen to blue
    ImageMaker::pen_blue = newB;
}
void ImageMaker::DrawPixel(int x, int y)
{
    // Pre: the coordinates are available on the image
    image[x][y][RED] = pen_red;
    image[x][y][GREEN] = pen_green;
    image[x][y][BLUE] = pen_blue;


    // Post: successfully draws a pixel
}

void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2)
{
    // Pre: The slopes of the values in Drawline are calculated correctly
    // Post: The method draws a rectangle successfully

    //line A->B
    DrawLine(x1, y1, x2, y1);
    //line A->C
    DrawLine(x1, y1, x1, y2);
    //line B->D
    DrawLine(x2, y1, x2, y2);
    //line C->D
    DrawLine(x1, y2, x2, y2);
}

void ImageMaker::DrawLine(int x1, int y1, int x2, int y2)
{
    // Pre: the equation of a line for this case is correct
    // Post: drawline successfully produces a line given the coordinates
    float m = 0;
    float b= 0;
    float x_value;
    x_value = (x2 - x1);
    //case for slope of infinity
    if (x_value == 0) {
        if (y1 < y2) {
            for (int i = y1; i < y2; i++) {
                DrawPixel(x1, i);

            }
        }
        else {
            for (int i = y2; i < y1; i++) {
                DrawPixel(x2, i);
            }
        }
    }
    // regular slope calculation
    else {


        m = (y2 - y1) / x_value;
        b = y1 - (m * x1);
    //condition for direction of drawing line in positive direction
    if(x1 < x2) {   
        for (int i = x1; i <= x2; i++) {
                y1 = (m * i) + b;
                DrawPixel(i, y1);


            }
        }
    //condition for drawing in the opposite direction
    else {
            for (int i = x2; i <= x1; i++) {

                y1 = (m * i) + b;
                DrawPixel(i, y1);
            }

        }
    }
            
   

    
    }
   
