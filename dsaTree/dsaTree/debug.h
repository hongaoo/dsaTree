#pragma once
#include <assert.h>
#define CHECK_NULL_PTR(Ptr)  do{if(Ptr == NULL){assert(Ptr);return -1;}}while (0)


