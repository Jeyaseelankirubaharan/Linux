#include <unistd.h>
#include <iostream>
#include <pthread.h>

using namespace std;

int *my_mem;

void* my_thread_1(void*);
void* my_thread_2(void*);


int main(int argc , char * argv[]) {

    pthread_t threads[5]; int thread_status;
    
    pthread_attr_t attr;

    cout << "Hello World!" << argc << endl;

    for(int i =0 ;i < argc ; i++)
    {
    	cout << argv[i] << endl;
    }

    int i = 0; int j = 0;

    thread_status = pthread_attr_init(&attr);

    while(i++ < 2)
    {
//    	sleep(1);
//
	if(i == 1)
	{

		thread_status = pthread_create(&threads[i],NULL,my_thread_1,NULL);
	}
	else
	{
		thread_status = pthread_create(&threads[i],NULL,my_thread_2,NULL);
	}
	
	if(thread_status == 0)
		printf("successfully created thread %d \n",threads[i]);
 	/*my_mem = (int*)malloc(10);
	free(my_mem);*/
    }

    i = 0;

    while(i++ < 2)
    {
    	if (pthread_join(threads[i], NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return -1;
    }
    }

    return 0;
}


void* my_thread_1(void*)
{
	int *p; int a=10;
	p = &a;
	printf("My thread function_1 \n");
	return (void*) p; 
}

void* my_thread_2(void*)
{
        int *p; int a=10;
        p = &a;
        printf("My thread function_2 \n");
        return (void*) p;
}

