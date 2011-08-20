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

