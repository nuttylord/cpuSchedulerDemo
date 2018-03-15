#include <iostream>
#include <fstream>
#include <string>

typedef struct Job 
{
    
}
int main ()
{
    std::string line;
    std::ifstream inputFile ("test.txt");
    
    if (inputFile.is_open())
    {
        while ( getline (inputFile, line) )
        {

        }
    }

    return 0; 
}