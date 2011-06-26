#ifndef _TestClass_
#define _TestClass_

#include <stdlib.h>
#include <stdio.h>

typedef struct _TestClass TestClass;

typedef void (*_setData) (struct _TestClass *, int);
typedef int (*_getData) (struct _TestClass *);

struct _TestClass {
	/*public member data and menber func*/
	int data;
	_setData setDataFunc;
	_getData getDataFunc;
};

static void setData(struct _TestClass *object, int n) { object->data = n; }; //printf("%d\n", object->data); };
static int  getData(struct _TestClass *object) { return object->data; }; 

#endif
