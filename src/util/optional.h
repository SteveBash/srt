#ifndef _optional_h
#define _optional_h

struct Optional{
    int pid;
};

typedef struct Optional Optional;

Optional Optional_of(int pid);
Optional Optional_absent();
int Optional_get(Optional o);
int Optional_is_present(Optional o);

#endif
