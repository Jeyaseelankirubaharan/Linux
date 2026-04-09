#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include "my_thread_1.hpp"
#include <semaphore.h>

extern std::string line;

std::string my_line;

extern sem_t mutex;

extern sem_t data_ready;

extern sem_t data_consumed;
using namespace std;


void* my_thread_1(void*)
{
       /* int *p; int a=10;
        p = &a;
        printf("My thread function_1 \n");
        return (void*) p;*/

    // Create an input file stream object and open the file
    istream &a = cin;

    ifstream inputFile("hello_world.txt");

    // Check if the file opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << std::endl;
        return (void *) 0;
    }

    

    while(std::getline(inputFile, my_line))
    {
        sem_wait(&data_consumed);
        
        sem_wait(&mutex);

        line = my_line;
	   
	    cout << "Read Successful" << line << endl;

         sem_post(&mutex);
         sem_post(&data_ready);
         //sem_wait(&data_ready);
	    
    }

    

    // Read the file line by line until the end of the file is reached
   /* while (std::getline(inputFile, line)) {
        // Process the line (e.g., print it to the console)
//	sem_wait(&mutex);
        std::cout << line << std::endl;
	sem_post(&mutex);
    }*/

    // Close the file
    inputFile.close();

    return (void*) 0 ;
}

