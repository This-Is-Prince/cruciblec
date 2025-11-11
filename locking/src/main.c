#include <stdio.h>
#include <stdbool.h>

#include "thread_mutex.h"
#include "process_file_locking.h"
#include "fcntl.h"
#include "thread_rw_lock.h"

int main(int argc, char* argv[]) {
    
    ThreadMutex(false);
    ProcessFileLocking(false, argc, argv);
    FileControl(false);
    ThreadRWLock(true);

    return 0;
}