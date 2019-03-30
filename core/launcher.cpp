#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

    string filepath(argv[0]);
    cout << "filepath = " << filepath << endl;

    string launcher("launcher.exe");

    filepath.erase(filepath.find("launcher.exe"), launcher.length());
    cout << "filepath = " << filepath << endl;

    string pluginsPath = filepath + "plugins\\";
    cout << "pluginsPath = " << pluginsPath << endl;

    string mainPath = filepath + "main.exe";
    cout << "mainPath = " << mainPath << endl;

    wstring pluginsFolder = wstring(pluginsPath.begin(), pluginsPath.end());
    cout << "pluginsFolder = " << pluginsFolder.c_str() << endl;
    //PCWSTR pluginsFolder = tpmPlugin.c_str();
    if (SetDefaultDllDirectories(LOAD_LIBRARY_SEARCH_APPLICATION_DIR)){
        cout << "SetDefaultDllDirectories success" << endl;
    }else{
        cout << "SetDefaultDllDirectories error" << endl;
    }

    DLL_DIRECTORY_COOKIE cookie = AddDllDirectory(pluginsFolder.c_str());
    if (cookie)
        cout << "AddDllDirectory success" << endl;
    else
        cout << "AddDllDirectory error" << endl;

    if (SetDllDirectoryA(pluginsPath.c_str()))
        cout << "SetDllDirectoryA success" << endl;
    else
        cout << "SetDllDirectoryA error" << endl;

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // Start the child process. 
    if(!CreateProcessA(mainPath.c_str(),   // No module name (use command line)
        NULL,           // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi )           // Pointer to PROCESS_INFORMATION structure
    ) 
    {
        std::printf( "CreateProcess failed (%d).\n", GetLastError() );
        return -1;
    }

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

   if (RemoveDllDirectory(cookie)){
        std::printf("DLL folder removed successfully\n");
    }else{
        std::printf( "DLL folder removing  failed (%d).\n", GetLastError());
    }

    return 0;
}

