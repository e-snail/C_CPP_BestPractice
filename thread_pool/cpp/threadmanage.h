#ifndef THREADMANAGE_H
#define THREADMANAGE_H

class Job;

class ThreadManage {
private:
	ThreadPool *m_threadpool;
	int m_numberofthread;

public:
    void setParallelNum(int num);
    ThreadManage();
    ThreadManage(int num);
    virtual ~CThreadManage();
 
    void run(Job* job,void* jobdata);
    void terminateAll(void);
};

#endif
