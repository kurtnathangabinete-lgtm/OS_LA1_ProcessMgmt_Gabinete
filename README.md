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


        TASK B
   The parent process (create_two_children.c) creates two children using CreateProcess().

Each child (child_echo.c) reports its Process ID (PID) and stays alive for 5 seconds.

The parent waits for both children to finish using WaitForMultipleObjects().

Compile child:

gcc child_echo.c -o child_echo.exe


Compile parent:

gcc create_two_children.c -o create_two_children.exe


Run parent program:

./create_two_children.exe


Observe that it spawns two child processes.

Use PowerShell to inspect running processes before and after:

Get-Process -Name create_two_children, child_echo -ErrorAction SilentlyContinue