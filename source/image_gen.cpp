#include"image_gen.h"

Image::Image(size_t newWidth, size_t newHeight)
{
    height = newHeight;
    width = newWidth;

    data = new byte**[height];

    for (size_t i = 0; i < height; i++)
    {
        data[i] = new byte*[width];
        for (size_t j = 0; j < width; j++)
        {
            data[i][j] = new byte[3];
        }
    }
    
}

Image::~Image()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            delete[] data[i][j];
        }
        
        delete[] data[i];
    }
    delete[] data;

    delete &width;
    delete &height;
}

void Image::SetPixel(size_t xPos, size_t yPos, byte R, byte G, byte B)
{
    data[yPos][xPos][0] = R;
    data[yPos][xPos][1] = G;
    data[yPos][xPos][2] = B;
}

void Image::SaveFile(std::string fileName)
{
    std::ofstream file(fileName);
    file << "P3\n" << width << " " << height << "\n";
    file << "255\n";
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            file << data[i][j][0] - 0 << " " << data[i][j][1] - 0 << " " << data[i][j][2] - 0 << " ";
        }
        file<< "\n";
    }
    file.close();
}