#ifndef GLOBALDEF_H
#define GLOBALDEF_H

typedef TaskFunc  void (*function)(void*)
typedef Argument void *args;

typedef MaxThreadNumber 10

enum Status {Available = 1, Running = 2, Unused = 255};

#endif
