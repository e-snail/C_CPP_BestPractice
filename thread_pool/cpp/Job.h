#ifndef JOB_H
#define JOB_H

class Thread;

class Job {
private:
	int m_jobNo;
	int m_jobName;
	Thread *m_pWorkThread;
public:
	Job();
	virtual ~Job();
	
    int	getJobNo(void) const { return m_jobNo; }
    void setJobNo(int jobno){ m_jobNo = jobno;}

	char* getJobName(void) const { return m_jobName; }
    void setJobName(char* jobname);

	Thread *getWorkThread(void) { return m_pWorkThread; }
    void	setWorkThread ( Thread *pWorkThread ){ m_pWorkThread = pWorkThread; }

	virtual void run(void* jobdata) = 0;
};

#endif
