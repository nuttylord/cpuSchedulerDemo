//#define _GLIBCXX_USE_C99 1 // specific g++ error with stoi.

#include "main.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <queue>

#include <vector>
#include <string> // not 100% efficient(char*[]) but it works on the fly!

#include <sstream>

namespace patch // this is here due to a bug with g++ (all hail the almighty g++ for it is flawed too like us)
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


using std::queue;

// i use a struct because its lightweight and usable on the fly,
// less overhead than making a class and also no need to
struct Job
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
		return "id: " + job_id + ", arrival time: " + patch::to_string(arrival_time) + ", duration: " + patch::to_string(duration) + ".";
	}

	std::string job_id;
	int arrival_time;
	int duration;
};

int main (int argc, char* argv[])
{
//	std::cout << "0" << argv[0] << std::endl;
//	std::cout << "1" << argv[1] << std::endl;
std::string obj = argv[0];
//std::cout << "2" << obj.substr(0) << std::endl;
//std::cout << "3" << obj.substr(2) << std::endl;
	//std::string obj = argv[0];
	std::string line;
   	std::ifstream inputFile ("demo_input" + obj.substr(6) + ".txt");
	queue<Job> jobList;
	Job x;

	std::cout << "? This is the generated list of inputs" << std::endl;
	for (int i = 1; i < argc ; i++) {
		std::cout << argv[i] << std::endl;
	}
	if (inputFile.is_open())
	{
		while ( getline (inputFile, line) )
		{
			std::cout << " .. " << line << std::endl;

			x.job_id = line.substr(0, line.find(" "));
			x.arrival_time = std::stoi(line.substr(line.find(" "), line.find(" ")).c_str());
			x.duration = std::stoi(line.substr(line.find_last_of(" ")).c_str());
			jobList.push(x);
        	}
	}
//	std::cout << "? This is the generated list of inputs" << std::endl;
//	while (!jobList.empty())
//	{
//		std::cout << jobList.front().toString() << std::endl;
//		jobList.pop();
//	}

	system("pause");
    return 0;
};
