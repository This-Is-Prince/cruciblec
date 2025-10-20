#include "openfile.h"
#include "logfile.h"
#include "seekfile.h"
#include "statfile.h"
#include "lockfile.h"

int main() {
    OpenFile(false);
    OpenLogFile(false);
    SeekFile(false);
    StatFile(false);
    LockFile(true);

    return 0;
}