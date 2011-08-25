#include <job.h>

#include <string>

using namespace std;

Job::Job(void)
	:m_pWorkThread(NULL),
	m_jobNo(0),
	m_jobName(NULL)
{
}

Job::~Job()
{
    if(NULL != m_jobName)
    	free(m_jobName);
}

void Job::setJobName(char* jobname)
{
    if( NULL !=m_jobName)    {
        free(m_jobName);
        m_jobName = NULL;
    }
    if(NULL != jobname)    {
        m_jobName = (char*)malloc(strlen(jobname)+1);
        strcpy(m_jobName,jobname);
    }
}
