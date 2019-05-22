#include<string>
#include<iostream>
#include<chrono>
void AssertInitialization(int argc, char const *argv[], size_t *blockSize, std::string * outputFolder, std::string *input, int *maxgen, std::chrono::seconds *duration)
{
    for (int i = 1; i < argc; i++)
    {
        //std::cout << (std::string)argv[i] << " | ";
        if((std::string)argv[i] == "--h" || (std::string)argv[i] == "-h" || (std::string)argv[i] == "--help")
        {
            std::cout <<"Usage: " << argv[0] << "[<options>] -input <filename> \n"
                      <<"--help               ->    Print this help text.\n"
                      <<"-input <filename>    ->    Name of the file used for input. \n"
                      <<"--imgdir <path>      ->    Specify directory where output images are written to. Make sure that the folder exists.\n"
                      <<"--maxgen <num>       ->    Maximum number of generations to simulate. \n"
                      <<"--fps <num>          ->    Number of generations to be presented per second. Default: 1 \n"
                      <<"--blocksize <num>    ->    Pixel size of a cell. Default: 10 \n"
                      <<"--bkgcolor <color>   ->    Color name for the background. Default: Green \n"
                      <<"--alivecolor <color> ->    Color name for representing alive cells. Default: Red \n"
                      <<"--outfile <filename> ->    Output filename for storing the text representations of the simulation. \n \n \n"
                      <<"Available colors: BLACK GRAY WHITE RED PURPLE BLUE CIAN GREEN YELLOW"
                      << std::endl;
            exit(0);
        }
        else if((std::string)argv[i] == "-input")
        {
            std::cout << "Set input as " << (std::string)argv[i+1] << std::endl;
            *input = (std::string)argv[i+1];
        }
        else if((std::string)argv[i] == "--imgdir")
        {
            std::cout << "Set output folder for the images as " << (std::string)argv[i+1] << std::endl;
            *outputFolder = (std::string)argv[i+1];
        }
        else if((std::string)argv[i] == "--maxgen")
        {
            std::cout << "Set max generation as " << (std::string)argv[i+1] << std::endl;
            *maxgen = atoi( argv[i + 1] );
        }
        else if((std::string)argv[i] == "--fps")
        {
            std::cout << "Set FPS to " << argv[i + 1] << std::endl;
            *duration = (std::chrono::seconds) atoi(argv[i + 1])/60; 
        }
        else if((std::string)argv[i] == "--blocksize")
        {
            *blockSize = atoi(argv[i + 1]);
            std::cout << "Set block size" << std::endl;
        }
        else if((std::string)argv[i] == "--bkgcolor")
        {
            /* Code */
        }
        else if((std::string)argv[i] == "--alivecolor")
        {
            /* Code */
        }
        else if((std::string)argv[i] == "--outfile")
        {
            /* Code */
        }
    }
    
}
