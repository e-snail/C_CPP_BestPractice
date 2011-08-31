#include "threadmanage.h"
#include "threadpool.h"

ThreadManage::ThreadManage()
{
	m_numberofthread = 10;
	m_threadpool = new ThreadPool(m_numberofthread);
}

ThreadManage::ThreadManage(int num)
{
	m_numberofthread = num;
	m_threadpool = new ThreadPool(m_numberofthread);
}

ThreadManage::~ThreadManage()
{
	if(m_threadpool) {
		delete m_threadpool;
	}
}

void ThreadManage::run(Job* job,void* jobdata)
{
	m_threadpool->run(job, jobdata);
}

void ThreadManage::terminateAll(void)
{
	m_threadpool->terminaterAll();
}
