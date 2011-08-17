#ifndef THREADINSTANCE_H
#define THREADINSTANCE_H

#include <pthread.h>
#include <string.h>

class Thread {

private:
	int m_ErrCode;
	Semaphore m_ThreadSemaphore;
	unsigned long m_ThreadID;
	bool m_Detach;
	bool m_CreateSuspended;
	ThreadState m_ThreadState;

protected:
	inline void setErrorCode( int errCode ) { m_ErrCode = errCode; }
	static void *ThreadFunction(void*);

public:
	Thread();
	Thread(bool suppendAtCreated, bool detach);
	virtual ~Thread();
	virtual void Run() = 0;
	
	inline void setThreadState(ThreadState state) { m_ThreadState = state; }
	inline ThreadState getThreadState() { return m_ThreadState; }

	inline int getLastError() { return m_ErrCode; }
	
	void  setThreadName(char* thrname) { strcpy(m_ThreadName, thrname); }
	char* getTreadName() { return m_ThreadName; }

	int getThreadID(void) { return m_ThreadID; }

    bool setPriority(int priority) { m_priority = priority; };
    int  getPriority(void) { return m_priority; }
    int  getConcurrency(void);
    void setConcurrency(int num);
    bool detach(void);
    bool join(void);
    bool yield(void);
    int self(void);
	
	bool terminate();
	bool start();
	void exit();
	bool wakeUp();
};

#endif
