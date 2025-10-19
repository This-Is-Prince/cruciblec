#include "openfile.h"
#include "logfile.h"
#include "seekfile.h"

int main() {
    OpenFile(false);
    OpenLogFile(false);
    SeekFile(true);

    return 0;
}