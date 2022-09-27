#ifndef _TASK_H_
#define _TASK_H_

#include <stdio.h>

extern int sharedData;

void writeResource(int threadId);
void readResource(int threadId);

#endif
