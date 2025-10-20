#include "race_condition.h"
#include "mutex_lock.h"

int main() {
    RaceCondition(false);
    MutexLock(true);

    return 0;
}