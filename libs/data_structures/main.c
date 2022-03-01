#include "string/string_.h"
#include "string/tasks/allTaskTests.h"


int isChet(const int a) {
    return a % 2 == 0;
}

void output(const char *a, size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%c", a[i]);
    printf("\n");
}

int main() {

    test_tasks();


    return 0;
}