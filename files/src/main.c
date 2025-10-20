#include "openfile.h"
#include "logfile.h"
#include "seekfile.h"
#include "statfile.h"
#include "lockfile.h"
#include "linkfile.h"
#include "unlinkfile.h"
#include "symlinkfile.h"

int main() {
    OpenFile(false);
    OpenLogFile(false);
    SeekFile(false);
    StatFile(false);
    LockFile(false);
    LinkFile(false);
    UnlinkFile(false);
    SymLinkFile(true);

    return 0;
}