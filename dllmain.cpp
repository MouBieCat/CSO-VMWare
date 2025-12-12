#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE _Instance, DWORD _Reason, LPVOID _Reserved) {
    switch (_Reason) {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        break;

    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
    }

    return TRUE;
}