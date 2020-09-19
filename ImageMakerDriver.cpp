#include "ImageMaker.h"

#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    ImageMaker myImage;
    

    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output


    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;
    string command;        // operation to be executed
    string fileName;
    int x1 = 0, x2, y1, y2, color;
    int width, height;


    inFile.open("test_file.txt");



  
  

    if (!inFile)
    {
        cout << "File not found." << endl;
        exit(2);
    }

    inFile >> command;
    while (command != "Quit") {
        if (command == "DrawPixel") {

            inFile >> x1 >>y1;

            myImage.DrawPixel(x1, y1);
            cout << "Drawing Pixel at" << " "<<x1 << "," << y1 << endl;
            outFile << "Drawing Pixel at" << " "<<x1 << "," << y1 << endl;
        }

        else if (command == "DrawRectangle") {

            inFile >> x1 >> y1 >> x2 >> y2;

            myImage.DrawRectangle(x1, y1, x2, y2);
            cout << "Drawing Rectangle using the points " << " (" << x1 << "," << y1 << ") " << " " << " (" << x2 << "," << y2 << ") ";
            outFile << "Drawing Rectangle using the points " << " (" << x1 << "," << y1 << ") " << " " << " (" << x2 << "," << y2 << ") ";
        }
        else  if (command == "DrawLine") {

            inFile >> x1 >> y1 >> x2 >> y2;

            myImage.DrawLine(x1, y1, x2, y2);
            cout << "Drawing line the from points " << " (" << x1 << "," << y1 << ") " << " " << " (" << x2 << "," << y2 << ") ";
            outFile << "Drawing line from the points " << " (" << x1 << "," << y1 << ") " << " " << " (" << x2 << "," << y2 << ") ";
        }
        else   if (command == "SetColor") {

            inFile >> color;
            if (color == RED) {
                myImage.SetPenRed(color);
                cout << "setting color to red" << endl;
                outFile << "setting color to red" << endl;

            }
            else if (color == GREEN) {
                myImage.SetPenGreen(color);
                cout << "setting color to green" << endl;
                outFile << "setting color to green" << endl;
            }
            else {
                myImage.SetPenBlue(color);
                cout << "setting color to blue" << endl;
                outFile << "setting color to blue" << endl;

            }
        }
        else   if (command == "PrintRGB") {
            cout << myImage.GetPenRed() << endl;
            cout << myImage.GetPenGreen() << endl;
            cout << myImage.GetPenBlue() << endl;

            outFile << myImage.GetPenRed() << endl;
            outFile << myImage.GetPenGreen() << endl;
            outFile << myImage.GetPenBlue() << endl;
        }
        else   if (command == "SetSize") {
            inFile >> width;


            myImage.SetWidth(width);
            cout << "setting width" << endl;
            outFile << "setting width" << endl;

            inFile >> height;
            myImage.SetHeight(height);
            cout << "setting height" << endl;
            outFile << "setting height" << endl;
        }
        else if (command == "PrintSize") {
            cout << myImage.GetWidth() << " " << "X" << " " << myImage.GetHeight() << endl;
            outFile << myImage.GetWidth() << " " << "X" << " " << myImage.GetHeight() << endl;

        }
        else if (command == "Load") {
          
            inFile >> fileName;
            myImage.LoadImage(fileName);
            
            cout << "loading image" << endl;
            outFile << "loading image" << endl;
        }
        else if (command == "Save") {
            inFile >> fileName;
            myImage.SaveImage(fileName);
            
            cout << "saving file" << endl;
            outFile << "saving file" << endl;
        }
        inFile >> command;
    }
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


   
