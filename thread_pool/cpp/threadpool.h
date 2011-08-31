#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <pthread.h>

class Job;

class ThreadPool {
	friend class WorkerThread;
private:
	unsigned int m_Maxnum;
	unsigned int m_AvailLow;
	unsigned int m_AvailHigh;
	unsigned int m_AvailNum;
	unsigned int m_InitNum;

protected:
	WorkerThread *getIdleThread();
	
	void appendToIdleThread(WorkerThread* idlethread);
	void moveToBusyThread(WorkerThread*	idelthread);
	void moveToIdleThread(WorkerThread* busythread);
	
	void deleteIdleThread(int num);
	void createIdleThread(int num);

public:
	ThreadMutex m_busyMutex;
	ThreadMutex m_idleMutex;
	ThreadMutex m_jobMutex;
	ThreadMutex m_varMutex;

    Condition m_busyCond; //m_BusyCond is used to sync busy thread list
    Condition m_idleCond; //m_IdleCond is used to sync idle thread list
    Condition m_idleJobCond;  //m_JobCond is used to sync job list
    Condition m_maxNumCond;

	vector<WorkerThread*> m_threadList;
	vector<WorkerThread*> m_busyList;
	vector<WorkerThread*> m_idleList;

	ThreadPool();
	ThreadPool(int num);
	virtual ~ThreadPool();

	void setMaxNum(int num) { m_Maxnum = num; }
    int getMaxNum(void) {return m_Maxnum;}

    void setAvailLowNum(int minnum){m_AvailLow = minnum;}
    int getAvailLowNum(void) {return m_AvailLow;}

    void setAvailHighNum(int highnum){m_AvailHigh = highnum;}
    int getAvailHighNum(void){return m_AvailHigh;}

    int getActualAvailNum(void){return m_AvailNum;}

    int getAllNum(void){return m_threadList.size();}
    int getBusyNum(void){return m_busyList.size();}
    void setInitNum(int initnum){m_InitNum = initnum;}
    int getInitNum(void){return m_InitNum;}

	void terminateAll(void);
    void run(Job* job,void* jobdata);
};

#endif
