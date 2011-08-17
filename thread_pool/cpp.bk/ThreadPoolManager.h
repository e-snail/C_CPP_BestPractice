#ifndef THREADPOOLMANAGER_H
#define THREADPOOLMANAGER_H

namespace ThreadPool { 

class ThreadIntance;
class TaskManager;
class Task;

class ThreadPoolManager {

public :
	ThreadPoolManager();
	~ThreadPoolManager();

	void addThreadInstance(ThreadIntance *i);	
	void removeThreadInstance(ThreadIntance *i);	

	List<ThreadIntance> availableTI();
	List<ThreadIntance> workingTI();

	void dealWithTask(Task);

private:
	List<ThreadIntance> availableTI();
	List<ThreadIntance> workingTI();
};

}
#endif
