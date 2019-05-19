#include<string>
#include<iostream>
void AssertInitialization(int argc, char const *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        if(argv[i] == "--h" || argv[i] == "-h" || argv[i] == "-help")
        {
            std::cout <<"Usage: " << argv[0] << "[<options>] <input_cfg_file> \n"
                      <<"-- help              ->    Print this help text.\n"
                      <<"--imgdir <path>      ->    Specify directory where output images are written to.\n"
                      <<"--maxgen <num>       ->    Maximum number of generations to simulate. \n"
                      <<"--fps <num>          ->    Number of generations to be presented per second. \n"
                      <<"--blocksize <num>    ->    Pixel size of a cell. Default: 1 \n"
                      <<"--bkgcolor <color>   ->    Color name for the background. Default: Green \n"
                      <<"--alivecolor <color> ->    Color name for representing alive cells. Default: Red \n \n \n"
                      <<"--outfile <filename> ->    Output filename for storing the text representations of the simulation."
                      <<"Available colors: BLACK GRAY WHITE RED PURPLE BLUE CIAN GREEN YELLOW"
                      << std::endl;
            exit(0);
        }
        else if(argv[i] == "--maxgen")
        {
            /* Code */
        }
        else if(argv[i] == "--fps")
        {
            /* Code */
        }
        else if(argv[i] == "--blocksize")
        {
            /* Code */
        }
        else if(argv[i] == "--bkgcolor")
        {
            /* Code */
        }
        else if(argv[i] == "--alivecolor")
        {
            /* Code */
        }
        else if(argv[i] == "--outfile")
        {
            /* Code */
        }
    }
    
}
