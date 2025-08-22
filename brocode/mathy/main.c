#include <stdio.h>
#include <math.h>

int main() {
    int x = 9;

    // x = sqrt(x);
    x = pow(x, 2);

    float y = 3.14;
    // y = round(y);
    // y = ceil(y);
    y = floor(y);

    printf("%d\n", x);
    printf("%f\n", y);

    return 0;
}