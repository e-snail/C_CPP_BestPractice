#include "threadpool.h"
#include "thread.h"
#include <assert.h>

ThreadPool::ThreadPool {
    m_MaxNum = 50;
    m_AvailLow = 5;
    m_InitNum = m_AvailNum = 10 ;  
    m_AvailHigh = 20;

	m_busyList.clear();
	m_idleList.clear();
	
	for (int i=0; i< m_initNum; i++ ) {
		WorkerThread *t = new WorkerThread();
		t->setThreadPool(this);
		appendToIdleThread(t);
		t->start();
	}
}

ThreadPool::ThreadPool(int initnum)
{
    assert(initnum>0 && initnum<=30);

    m_maxNum = 30;
    m_availLow = initnum-10>0?initnum-10:3;
    m_initNum=m_availNum = initnum ;  
    m_availHigh = initnum+10;
 
    m_busyList.clear();
    m_idleList.clear();

    for(int i=0;i<m_initNum;i++){
    WorkerThread* thr = new WorkerThread();
    appendToIdleList(thr);
    thr->setThreadPool(this);
    thr->start();       //begin the thread,the thread wait for job
    }
}


ThreadPool::~ThreadPool {
	terminateAll();
}

void ThreadPool::terminateAll()
{
	for (int i=0; i<m_threadList.size(); i++) {
		WorkerThread *t = m_threadList[i];
		t->join();
	}
	return;
}

WorkerThread *ThreadPool::getIdleThread()
{
	while (m_idleList.size() == 0)
		m_idleCond.Wait();

	m_idleMutex.lock();	
	if (m_idleList.size() > 0) {
		WorkerThread *t = (WorkerThread*)m_idleList.front();
		printf("Get idle thread %d\n", t->getThreadId());
		m_idleMutex.unlock();
		return t;
	}
	m_idleMutex.unlock();

	return NULL;
}

void ThreadPool::appendToIdleList(WorkerThread* jobthread)
{
	m_idleMutext.lock();
	m_idleList.push_back(jobthead);
	m_threadList.push_back(jobthread);
	m_idleMutex.unlock();
	
}

void ThreadPool::moveToBusyList(WorkerThread* idlethread)
{
	m_busyMutex.lock();
	m_busyList.push_back(idlethread);
	m_AvailNum--;
	m_busyMutex.unlock();

	m_idleMutex.lock();
	vector<WorkerThread *>::iterator pos;
	pos = find(m_idleList.begin(), m_idleList.end(), idlethread);
	if (pos != m_idleList.end()) {
		m_idleList.erease(pos);
	}
	m_idleMutex.unlock();
}

void ThreadPool::moveToIdleList(WorkerThread* busythread)
{
	m_idleMutex.lock();
	m_idleList.push_back(busythread);
	m_AvailNum++;
	m_idleMutex.unlock();

	m_busyMutex.lock();
	vector<WorkerThread *>::iterator pos;
	pos = find (m_busyList.begin(), m_busyList.end(), busythread);
	if (pos != m_busyList.end()) {
		m_busyList.erease(pos);
	}
	m_busyMutex.unlock();

	m_idleCond.signal(); //why following two condition emit signal ?
	m_maxNumCond.signal();
}

void ThreadPool::createIdleThread(int num)
{
	for (int i=0; i <num; i++ ) 
	{
		WorkerThread *t = new WorkerThread;
		t->setThreadPool(this);
		appendToIdleThread(t);
		m_varMutex.lock();
		m_AvailNum++;
		m_varMutex.unlock();
		this->start();
	}
}

void ThreadPool::DeleteIdleThread(int num)
{
	printf("Enter into CThreadPool::DeleteIdleThread/n");	
	m_idleMutex.lock();
	printf("Delete Num is %d/n",num);
	for (int i=0; i<num; i++) 
	{
		WorkerThread *t;
		if (m_idleThread.size() > 0 ) {
			t = m_idleList.front();
			printf("Get Idle thread %d/n",thr->GetThreadID());
		}
		vector<WorkerThread*>::iterator pos;
		pos = find (m_idleList.begin(), m_idleList.end(), t);
		if (pos != m_idleList.end() ) {
			m_idleList.erease(pos);
		}
		m_AvailNum--;
		printf("The idle thread available num:%d /n",m_AvailNum);
	    printf("The idlelist              num:%d /n",m_idleList.size());
	}
	m_idleMutex.unlock();
}

void ThreadPool::run(Job* job,void* jobdata)
{
	assert(job!=NULL);

	if (getBusyNum() == m_MaxNum)
		m_maxNumCond.wait();

	//当空闲线程数小于设定的最低空闲线程数时
    if(m_idleList.size() < m_AvailLow)
    {
		//如果创建后总数不超过m_MaxNum，则创建后的线程为m_InitNum；如果超过了，则只创建( m_MaxNum-当前线程总数 )个。
    	if(getAllNum() + m_InitNum - m_idleList.size() < m_MaxNum )
       	 	CreateIdleThread(m_InitNum - m_idleList.size());
    	else
        	CreateIdleThread(m_MaxNum - getAllNum());
    }
	

	WorkerThread *t = getIdleThread();
	if(t != NULL) {
		t->m_workMutex.lock();
		moveToBusyList(t);
		t->setThreadPool(this);
		job->setWorkerThread(t);
		printf("Job is set to thread %d /n",idlethr->GetThreadID());
		t->setJob(job, jobdata);
	}
}

