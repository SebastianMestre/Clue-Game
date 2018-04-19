#ifndef UTIL_MEMORY_H
#define UTIL_MEMORY_H

// memutil.h
#include <stdlib.h>
#include <assert.h>

#include "stddef.h"

void* safe_malloc(size_t size);

void* safe_realloc(void *p, size_t size);

#endif /* end of include guard: UTIL_MEMORY_H */
