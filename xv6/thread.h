// Thread library definition
int thread_create(void (*function) (void *), void *arg);
int thread_join(int tid);