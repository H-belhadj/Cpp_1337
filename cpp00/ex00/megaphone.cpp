

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    int i = 0;
    while(++i < argc)
    {
        char *arr = argv[i];
        int x = 0;
        int len = strlen(arr);
        while(x < len)
            putchar(toupper(arr[x++]));
    }
    return(0);
}