#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Child PID: %lu, Parent PID passed: %s\n", GetCurrentProcessId(), argv[1]);
    fflush(stdout);        // Ensure output prints immediately
    Sleep(15000);          // 15 seconds so you can check it
    return 0;
}
