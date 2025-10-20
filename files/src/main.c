#include "openfile.h"
#include "logfile.h"
#include "seekfile.h"
#include "statfile.h"
#include "lockfile.h"
#include "linkfile.h"
#include "unlinkfile.h"

int main() {
    OpenFile(false);
    OpenLogFile(false);
    SeekFile(false);
    StatFile(false);
    LockFile(false);
    LinkFile(true);
    UnlinkFile(false);

    return 0;
}