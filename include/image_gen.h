#include<string>
#include<fstream>

using byte = unsigned char;

class Image
{
    private: 
        size_t width, height;
        byte ***data;
    public:
        Image(size_t newWidth, size_t newHeight);
        ~Image();
        void SetPixel(size_t xPos, size_t yPos, byte R, byte G, byte B);
        void SaveFile(std::string fileName);
};