#include<string>
#include<fstream>
#include<iostream>

using byte = unsigned char;

namespace imgen{
    //! Image generator class
    /*! Class used for generating a .pnm file.
        \author Gabriel Lucena (fr4ct1ons)
        */
    class Image
    {
        private: 
            size_t width, height;
            size_t blockSize;
            byte ***data;
        public:
            //! Basic constructor
            Image(size_t newWidth, size_t newHeight, size_t newBlockSize=1);
            //! Basic destructor
            ~Image();
            //! Returns the image's block s
            size_t GetBlockSize();
            //! Sets a color on one pixel.
            void SetPixel(size_t xPos, size_t yPos, byte R, byte G, byte B);
            //! Saves the .pnm image.
            /*! \param fileName - Name of the file to save the image as.
                */
            void SaveFile(std::string fileName);
            //! Paints a chunk of the image with the same size as blockSize.
            /*! \param xInit - Initial X coordinate of the corner of where to paint the block
                \param yInit - Initial Y coordinate of the corner of where to paint the block
                */
            void PaintBlock(size_t xInit, size_t yInit, byte R, byte G, byte B);
    };
}