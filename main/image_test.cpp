#include"image_gen.h"

int main(int argc, char const *argv[])
{
    Image testImage(3,3);

    testImage.SetPixel(0,0,255,0,0);
    testImage.SetPixel(1,0,0,255,0);
    testImage.SetPixel(2,0,0,0,255);
    testImage.SetPixel(0,1,255,255,0);
    testImage.SetPixel(1,1,255,0,255);
    testImage.SetPixel(2,1,0,255,255);
    testImage.SetPixel(0,2,255,255,255);
    testImage.SetPixel(1,2,127,127,127);
    testImage.SetPixel(2,2,0,0,0);

    testImage.SaveFile("Test.ppm");

    std::cout << "All done! Closing app" << std::endl;
    return 0;
}


