#ifndef THREADINSTANCE_H
#define THREADINSTANCE_H

#include "globaldef.h"
#include <pthread.h>

class ThreadInstance  {
public:
//	ThreadInstance(int thread_id, Status status, Atrribute attr, Task task):
//		m_thread_id(thread_id),
//		m_status(status),
//		m_attr(attr),
//		m_task(task) {
//		}
	ThreadInstance();
	~ThreadInstance();

	void setThreadId(int id);
	void setStatus(Status status);
	void setAttribute(Attribute attr);
	void setTask(Task task);
	//getters

	void toExecute();

private:
	int m_thread_id;
	Status m_status;
	Attribute m_attr;
	Task m_task;
	pthread_t m_thread;
};

#endif

