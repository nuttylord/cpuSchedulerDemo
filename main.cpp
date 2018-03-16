#include "main.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <queue>

#include <vector>
#include <string> // not 100% efficient(char*[]) but it works on the fly! 

using std::queue;
// i use a struct because its lightweight and usable on the fly, 
// less overhead than making a class and also no need to
typedef struct Job
{
	Job() // default constructor 
		: job_id(""), arrival_time(0), duration(0)
	{};
	Job(std::string job_id, int arrival_time, int duration)
		: job_id(job_id), arrival_time(arrival_time), duration(duration)
	{
	};

	std::string toString()
	{
		return "id: " + job_id + ", arrival time: " + std::to_string(arrival_time) + ", duration: " + std::to_string(duration) + ".";
	}

	std::string job_id;
	int arrival_time;
	int duration;
};

int main ()
{
    std::string line;
    std::ifstream inputFile ("test.txt");
	queue<Job> jobList;
	Job x;
    if (inputFile.is_open())
    {
        while ( getline (inputFile, line) )
        {
			// input may be array (int main(args)) https://stackoverflow.com/questions/20234898/correct-way-of-loop-through-the-c-arrays
			
			std::cout << " .. " << line << std::endl;

			x.job_id = line.substr(0, line.find(" "));
			x.arrival_time = std::atoi(line.substr(line.find(" "), line.find(" ")).c_str());
			x.duration = std::atoi(line.substr(line.find_last_of(" ")).c_str());
			jobList.push(x);
        }
		std::cout << "done" << std::endl;
    }
	while (!jobList.empty())
	{
		std::cout << "out: " << jobList.front().toString() << std::endl;
		jobList.pop();
	}

	system("pause");
    return 0; 
};