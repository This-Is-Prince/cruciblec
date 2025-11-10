#include <stdio.h>
#include <stdbool.h>

#include "thread_mutex.h"
#include "process_file_locking.h"

int main(int argc, char* argv[]) {
    
    ThreadMutex(false);
    ProcessFileLocking(true, argc, argv);

    return 0;
}