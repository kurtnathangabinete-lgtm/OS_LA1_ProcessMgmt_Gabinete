// create_two_children.c
#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si1, si2;
    PROCESS_INFORMATION pi1, pi2;
    DWORD parentPID = GetCurrentProcessId();

    ZeroMemory(&si1, sizeof(si1));
    si1.cb = sizeof(si1);
    ZeroMemory(&pi1, sizeof(pi1));

    ZeroMemory(&si2, sizeof(si2));
    si2.cb = sizeof(si2);
    ZeroMemory(&pi2, sizeof(pi2));

    char cmd1[100], cmd2[100];
    sprintf(cmd1, "child_echo.exe %lu", parentPID);
    sprintf(cmd2, "child_echo.exe %lu", parentPID);

    printf("[Parent] PID: %lu\n", parentPID);

    // Start first child
    if (!CreateProcess(
        NULL,   // Application name
        cmd1,   // Command line
        NULL,   // Process handle not inheritable
        NULL,   // Thread handle not inheritable
        FALSE,  // Set handle inheritance to FALSE
        0,      // No creation flags
        NULL,   // Use parent's environment block
        NULL,   // Use parent's starting directory
        &si1,   // Pointer to STARTUPINFO structure
        &pi1)   // Pointer to PROCESS_INFORMATION structure
    ) {
        printf("CreateProcess for Child 1 failed (%lu).\n", GetLastError());
        return 1;
    }

    // Start second child
    if (!CreateProcess(
        NULL,
        cmd2,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si2,
        &pi2)
    ) {
        printf("CreateProcess for Child 2 failed (%lu).\n", GetLastError());
        return 1;
    }

    printf("[Parent] Spawned Child 1 PID: %lu\n", pi1.dwProcessId);
    printf("[Parent] Spawned Child 2 PID: %lu\n", pi2.dwProcessId);

    // Wait for both children
    HANDLE processes[2] = { pi1.hProcess, pi2.hProcess };
    WaitForMultipleObjects(2, processes, TRUE, INFINITE);

    DWORD exitCode1, exitCode2;
    GetExitCodeProcess(pi1.hProcess, &exitCode1);
    GetExitCodeProcess(pi2.hProcess, &exitCode2);

    printf("[Parent] Child 1 exited with code %lu\n", exitCode1);
    printf("[Parent] Child 2 exited with code %lu\n", exitCode2);

    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);
    CloseHandle(pi2.hProcess);
    CloseHandle(pi2.hThread);

    return 0;
}
