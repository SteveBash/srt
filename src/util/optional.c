#include <stdio.h>
#include "optional.h"

Optional Optional_of(int pid){
    return (Optional){.pid = pid};
}

Optional Optional_absent(){
    return (Optional){.pid = -1};
}

int Optional_get(Optional o){
    return o.pid;
}

int Optional_is_present(Optional o){
    if (o.pid == -1)
        return 0;
    else
        return 1;
}

