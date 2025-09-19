#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD exitCode;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    DWORD parentPID = GetCurrentProcessId();
    printf("Parent PID: %lu\n", parentPID);

    // Command line: child_echo.exe <parentPID>
    char cmdLine[256];
    sprintf(cmdLine, "child_echo.exe %lu", parentPID);

    // Create child process
    if (!CreateProcess(
            NULL,        // Application name
            cmdLine,     // Command line
            NULL,        // Process handle not inheritable
            NULL,        // Thread handle not inheritable
            FALSE,       // No handle inheritance
            0,           // No creation flags
            NULL,        // Use parent's environment
            NULL,        // Use parent's working dir
            &si,         // Startup info
            &pi)         // Process info
    ) {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }

    // Wait for child to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Get child’s exit code
    GetExitCodeProcess(pi.hProcess, &exitCode);
    printf("Child finished with exit code: %lu\n", exitCode);

    // Close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
