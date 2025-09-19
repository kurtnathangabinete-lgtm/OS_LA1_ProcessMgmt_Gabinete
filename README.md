# OS_LA1_ProcessMgmt_Gabinete

## 📌 Result
This project demonstrates **basic process management in Windows** using the Win32 API.  
It consists of:
- `create_basic.c`: Parent process that spawns a child.
- `child_echo.c`: Child process that displays its own PID and the parent’s PID.




### GCC version: VS Code with MinGW installed
1. Install **MSYS2 + MinGW-w64** (ensure `gcc` is in your PATH).
2. Clone this repository:
   ```terminal
   git clone https://github.com/kurtnathangabinete-lgtm/OS-Lab-GabineteKurtOS_LA1_ProcessMgmt_Gabinete.git
   cd OS_LA1_ProcessMgmt_Gabinete

    ```terminal
        TASK B
   The parent process (create_two_children.c) creates two children using CreateProcess().

Each child (child_echo.c) reports its Process ID (PID) and stays alive for 5 seconds.

The parent waits for both children to finish using WaitForMultipleObjects().
```terminal
Compile child:

gcc child_echo.c -o child_echo.exe

```terminal
Compile parent:

gcc create_two_children.c -o create_two_children.exe


```terminal
Task C – Simulating exec()

Description:
The parent program (replace_sim.exe) spawns a new process (example: cmd /c dir).
Parent waits for it to finish and exits with the same exit code as the spawned process.

```terminal
RUN:
gcc replace_sim.c -o replace_sim.exe

./replace_sim.exe

```terminal
Before running:

Get-Process -Name replace_sim, cmd -ErrorAction SilentlyContinue


Expected Output: Empty — neither parent nor child is running.

```terminal
After running:

Get-Process -Name replace_sim, cmd -ErrorAction SilentlyContinue