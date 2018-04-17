// memutil.c

void* safe_malloc(size_t size){
  size_t safe_size = size > 0 ? size : 1;
  void* p = malloc(safe_size);
  assert(p != NULL);

  return p;
}

void* safe_realloc(void *r, size_t size){
  size_t safe_size = size > 0 ? size : 1;

  void *p = *r == NULL
    ? malloc(safe_size)
    : realloc(t, safe_size);

  assert(p != NULL);

  return p;
}
