#include<string>
#include<fstream>
#include<iostream>

using byte = unsigned char;

namespace imgen{
    class Image
    {
        private: 
            size_t width, height;
            size_t blockSize;
            byte ***data;
        public:
            Image(size_t newWidth, size_t newHeight, size_t newBlockSize=1);
            ~Image();
            size_t GetBlockSize();
            void SetPixel(size_t xPos, size_t yPos, byte R, byte G, byte B);
            void SaveFile(std::string fileName);
            void PaintBlock(size_t xInit, size_t yInit, byte R, byte G, byte B);
            void PaintBlock(size_t xInit, size_t yInit, size_t blockOverride);
    };
}