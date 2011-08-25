#ifndef CONCRETEJOB_H
#define CONCRETEJOB_H

#include "job.h"

class ConcreteJob : public Job 
{
private:
	
public:
	ConcreteJob();
	~ConcreteJob();
	void run(void* jobdata) {
		printf("ConcreteJob running\n");
		sleep(2);
	}
};

#endif
