#include <curl/curl.h>
#include "histogram.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

int
main(int argc, char* argv[])
{
    const char* name = "Commander Shepard";
    int year = 2154;
    printf("%s was born in %d.\n", name, year);
    printf("n = %08x\n", 0x1234567);
    return 0;
    Input input;
    string option_value;

    if (argc > 1)
    {
        if(argv[3]== NULL)
        {
            cerr<<"after -fill you need to put one more argument";
            exit(1);
        }
        if(string(argv[2])=="-fill")
        {
            input = download(argv[1]);
            option_value =argv[3];
        }
        if(string(argv[1])=="-fill")
        {
            if(strstr(argv[2],"http://")== 0)
            {
                input = download(argv[3]);
                option_value =argv[2];
            }
            else
            {
                cerr<<"after -fill you need to put one more argument";
                exit(1);
            }
        }
    }
    else
    {
        input = read_input(cin,false);
    }
    const auto bins = make_histogram(input);
    auto bin_size = fun_sign(input);
    show_histogram_svg(bins,bin_size,option_value);

    return 1;
}

