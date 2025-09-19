#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[]) {
    DWORD pid = GetCurrentProcessId();   // Child PID
    DWORD ppid = 0;

    if (argc > 1) {
        ppid = (DWORD)atoi(argv[1]);     // Parent PID passed as arg
    }

    printf("Child process started!\n");
    printf("Child PID: %lu\n", pid);
    printf("Parent PID (from arg): %lu\n", ppid);

    // Keep the child alive for 5 seconds
    printf("Child will stay alive for 5 seconds...\n");
    Sleep(15000); // 15 seconds


    printf("Child process exiting now.\n");
    return 0;
}
