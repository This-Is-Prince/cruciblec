#include <stdio.h>

int main() {
    int i = 5;
    int j = i++;

    printf("i is %d\n", i);
    printf("j is %d\n", j);

    int ii = 5;
    int jj = ++ii;
    
    printf("ii is %d\n", ii);
    printf("jj is %d\n", jj);

    return 0;
}