#include"image_gen.h"

int main(int argc, char const *argv[])
{
    Image testImage(3,3, 10);
    size_t testVal = testImage.GetBlockSize();

    testImage.PaintBlock(0 * testVal,0 * testVal,255,0,0);
    testImage.PaintBlock(1 * testVal,0 * testVal,0,255,0);
    testImage.PaintBlock(2 * testVal,0 * testVal,0,0,255);
    testImage.PaintBlock(0 * testVal,1 * testVal,255,255,0);
    testImage.PaintBlock(1 * testVal,1 * testVal,255,0,255);
    testImage.PaintBlock(2 * testVal,1 * testVal,0,255,255);
    testImage.PaintBlock(0 * testVal,2 * testVal,255,255,255);
    testImage.PaintBlock(1 * testVal,2 * testVal,127,127,127);
    testImage.PaintBlock(2 * testVal,2 * testVal,0,0,0);
    

    testImage.SaveFile("Test.ppm");

    std::cout << "All done! Closing app" << std::endl;
    return 0;
}


