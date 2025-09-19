#include <stdio.h>
#include <windows.h>

int main() {
    DWORD pid = GetCurrentProcessId();
    printf("Child process started. PID = %lu\n", pid);

    // Keep the child alive for 5 seconds
    Sleep(5000);

    printf("Child process exiting. PID = %lu\n", pid);
    return 0;
}
