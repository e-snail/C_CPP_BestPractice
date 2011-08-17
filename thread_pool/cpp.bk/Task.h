#ifndef TASK_H
#define TASK_H

#include "globaldef.h"

namespace ThreadPool {

class Task {
public:
	Task(TaskFunc f, Argument args=NULL, attached=false);
	~Task();

	inline void setAttached(const bool attach) { m_attached = attach; };
	inline bool getAttached() { return m_attached; };
	
private:
	TaskFunct m_func;
	Argument m_args;
	bool m_attached;
};

}

#endif
