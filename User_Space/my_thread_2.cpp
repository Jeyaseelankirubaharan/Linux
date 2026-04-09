#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include "my_thread_2.hpp"
#include <thread>
#include <chrono>
#include <fstream>

extern std::string line;

extern sem_t mutex;

extern sem_t data_ready;

extern sem_t data_consumed;

void* my_thread_2(void*)
{
        int count = 0;
        

	std::ofstream outFile("example.txt");

//	std::this_thread::sleep_for(std::chrono::milliseconds(1));
//
	while (count ++ < 3)
	{
		sem_wait(&data_ready);

		sem_wait(&mutex);

		//std::cout << "My thread function_1 " << line << std::endl;

		if (outFile.is_open()) {
        	// 3. Write a line using the << operator
        		outFile << line  << std::endl;
		}
       		else {
        		std::cerr << "Unable to open file" << std::endl;
   		}

		sem_post(&mutex);
		sem_post(&data_consumed);
	}

	 // 4. Close the file (good practice)
        outFile.close();

        return (void*) 0;
}
