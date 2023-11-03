#include <iostream>
#include <cstring>
#include "bmplib.cpp"

unsigned char RGBImage[SIZE][SIZE][RGB];

void loadRGB();
void saveRGB();
void menu();
void bwFilter();
void Invert();
void Darken();
void Lighten();

int main()
{

    menu();
}




void menu()
{
    char ch;
    cout << "Please select a filter to apply or 0 to exit:\n";
    cout << "1-	Black & White Filter\n";
    cout << "2-	Invert Filter\n";
    cout << "3-	Darken and Lighten Image\n";
    cout << "s- For save Image\n";
    cout << "0- For Exit\n";
    cout<<"you choose : ";cin >> ch;
    while (ch)
    {
        if (ch == '0')
        {
            cout << "Exit done\n";
            break;
        }

        else if (ch == '1')
            bwFilter();

        else if (ch == '2')
            Invert();

        else if (ch == '3')
        {
            char mode;
            cout << "Do you want to (d)arken or (l)ighten ?\n";
            cin >> mode;

            if (mode == 'l')
                Lighten();
            if (mode == 'd')
                Darken();
        }

        else if (ch == 's')
            saveRGB();

    }
}

void loadRGB()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, RGBImage);
}

void saveRGB()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, RGBImage);
}

void bwFilter()
{
    loadRGB();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                if (RGBImage[i][j][k] > 100)
                    RGBImage[i][j][k] = 0;
                else
                    RGBImage[i][j][k] = 255;
            }
        }
    }
    saveRGB();
}

void Invert()
{
    loadRGB();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                RGBImage[i][j][k] = 255 - RGBImage[i][j][k];
            }
        }
    }
    saveRGB();
}

// Lighten

void Lighten()
{
    loadRGB();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                if (RGBImage[i][j][k] <= 190)
                    RGBImage[i][j][k] += 65;
            }
        }
    }
    saveRGB();
}

// Darken

void Darken()
{
    loadRGB();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                RGBImage[i][j][k] = RGBImage[i][j][k] / 2;
            }
        }
    }
    saveRGB();
}