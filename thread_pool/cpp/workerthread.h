#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include "thread.h"

class Job;
class ThreadPool;

class WorkerThread : public Thread {
private:
	ThreadPool *m_threadpool;
	Job *m_job;
	void *m_jobdata;
	bool m_isEnd;
	ThreadMutext m_varMutext;
public:
	Condition m_jobCon;
	ThreadMutex m_workMutex;

	WorkerThread();
	virtual ~WorkerThread();
	void run();
	void setJob(Job*, void *jobdata);
	Job* getJob() {	return m_job; }
	void setThreadPool(ThreadPool *pool);
	ThreadPool *getThreadPool() { return m_threadpool; }
};

#endif
