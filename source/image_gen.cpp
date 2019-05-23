#include"image_gen.h"
#include"lodepng.h"

namespace imgen{
    Image::Image(size_t newWidth, size_t newHeight, size_t newBlockSize)
    {
        blockSize = newBlockSize;
        height = newHeight * blockSize;
        width = newWidth * blockSize;

        data = new byte**[height];

        for (size_t i = 0; i < height; i++)
        {
            data[i] = new byte*[width];
            for (size_t j = 0; j < width; j++)
            {
                data[i][j] = new byte[4];
            }
        }

        for (int i = 0; i < height; i++)
        {
        	for (int j = 0; j < width; j++)
        	{
        		for (int k = 0; k < 4; k++)
        		{
        			/* code */
        		}
        	}
        }
        dataSolo = new byte[width * height * 4];
        //std::cout << "Instatntiated image. Size is [" << height - 1 << "] [" << height - 1 << "][2]" << std::endl;
    }

    Image::~Image()
    {
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                delete[] data[i][j];
            }
        }
        //std::cout << "Deleted 3 sized array"<< std::endl;
        for (size_t i = 0; i < height; i++)
        {   
            delete[] data[i];
        }
        //std::cout << "Deleted width sized array"<< std::endl;
        delete[] data;
        //std::cout << "Deleted everything"<< std::endl;
        delete[] dataSolo;

        //delete &width;
        //std::cout << "Deleted width value"<< std::endl;
        //delete &height;
        //std::cout << "Deleted image successfully" << std::endl;
    }

    size_t Image::GetBlockSize(){ return blockSize; }

    void Image::SetPixel(size_t xPos, size_t yPos, byte R, byte G, byte B)
    {
        data[yPos][xPos][0] = R;
        //std::cout << "Placed pixel at [" << yPos << "] [" << xPos << "][0]" << std::endl;
        data[yPos][xPos][1] = G;
        //std::cout << "Placed pixel at [" << yPos << "] [" << xPos << "][1]" << std::endl;
        data[yPos][xPos][2] = B;
        //std::cout << "Placed pixel at [" << yPos << "] [" << xPos << "][2]" << std::endl;
        data[yPos][xPos][3] = 255;
    }

    void Image::SaveFile(std::string fileName)
    {
        std::ofstream file(fileName);
        //std::cout << "created ofstream" << std::endl;
        file << "P3\n" << width << " " << height << "\n";
        file << "255\n";
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                file << data[i][j][0] - 0 << " " << data[i][j][1] - 0 << " " << data[i][j][2] - 0 << " ";
                //std::cout << "saved pixel at [" << i << "][" << j << "]" << std::endl;
            }
            //std::cout << "saved line on file"<< std::endl;
            file<< "\n";
        }
        //std::cout << "closing file "<< std::endl;
        file.close();
        //char nameChar[fileName.size()];
        int buffer = 0;
        for (int i = 0; i < height; i++)
        {
        	for (int j = 0; j < width; j++)
        	{
        		for (int k = 0; k < 4; k++)
        		{
        			dataSolo[buffer] = data[i][j][k];
        			buffer++;
        		}
        	}
        }

        encode_png(fileName, dataSolo, width, height);
    }

    void Image::encode_png(std::string filename, unsigned char * image, size_t width, size_t height)
	{
	    //Encode the image
	    unsigned error = lodepng::encode(filename, image, width, height);

	    //if there's an error, display it
	    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
	}

    void Image::PaintBlock(size_t xInit, size_t yInit, byte R, byte G, byte B)
    {
        for (size_t i = 0; i < blockSize; i++)
        {
            for (size_t j = 0; j < blockSize; j++)
            {
                SetPixel(xInit + j, yInit + i,R,G,B);
            }
        }
    }
}