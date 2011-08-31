#include "workerthread.h"

WorkerThread::WorkerThread() 
{
	m_job = NULL;
    m_jobdata = NULL;
    m_threadpool = NULL;
    m_isEnd = false;
}

WorkerThread::~WorkerThread()
{
    if (NULL != m_job) {
    	delete m_job;
	}

    if (m_threadpool != NULL) {
    	delete m_threadpool;
	}
}

void WorkerThread::run()
{
	SetThreadState(THREAD_RUNNING);
	for (;;) {
		while (m_job == NULL) {
			m_jobCon.wait();
		}
		m_job->run(m_jobdata);
		m_job->setWorkThread(NULL);
		m_job = NULL;
		m_threadpool->moveToIdleList(this);

		if(m_threadpool->m_idleList.size() > m_threadpool->getAvailHighNum())
    	{
			m_threadpool->deleteIdleThread(
					m_threadpool->m_idleList.size() - m_threadpool->getInitNum());
    	}
		m_workMutex.unlock();
	}
}

void WorkerThread::setJob(Job *job, void *jobdata) 
{
	m_varMutext.lock();

	m_job = job;
	m_jobdata = jobdata;
	m_job.setWorkThread(this);
	m_varMutext.unlock();

	m_jobCon.signal();
}

void WorkerThread::setThreadPool(ThreadPool *pool) 
{
	m_varMutext.lock();
	m_threadpool = pool;
	m_varMutext.unlock();
}
