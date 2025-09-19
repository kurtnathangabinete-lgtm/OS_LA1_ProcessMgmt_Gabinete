#include <windows.h>
#include <stdio.h>

int main(void) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD exitCode;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Command to execute: cmd /c dir
    char command[] = "cmd.exe /c dir";

    printf("Parent (replace_sim) starting...\n");

    // Create process (simulate exec)
    if (!CreateProcess(
            NULL,        // Application name
            command,     // Command line
            NULL,        // Process handle not inheritable
            NULL,        // Thread handle not inheritable
            FALSE,       // Set handle inheritance to FALSE
            0,           // No creation flags
            NULL,        // Use parent's environment block
            NULL,        // Use parent's starting directory
            &si,         // Pointer to STARTUPINFO structure
            &pi)         // Pointer to PROCESS_INFORMATION structure
    ) {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }

    // Wait until child process ends
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Get exit code of child process
    if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
        printf("Child process exited with code %lu\n", exitCode);
    } else {
        printf("Failed to get child process exit code.\n");
    }

    // Close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    // Exit with same code as child
    return (int)exitCode;
}
