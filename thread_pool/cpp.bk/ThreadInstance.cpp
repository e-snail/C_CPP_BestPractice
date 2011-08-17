#include "ThreadInstance.h"

#include <pthread.h>
#include <string.h>

ThreadInstance::ThreadInstance() {
	memset(&m_thread, 0, sizeof(pthread_t));
	if ( pthread_create(&m_thread, NULL,  ) )
}
