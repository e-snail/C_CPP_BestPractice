#include "ThreadManager.h"
#include "ConcreteJob.h"

int main(int argc, char** argv)
{
	ThreadManager *manager = new ThreadManager(10);
	for (int i=0; i<40; i++ ) {
		ConcreteJob *job = new ConcreteJob;
		manager->run(job, NULL);
	}
	sleep(2);

	manager->terminateAll();

	return 0;
}
