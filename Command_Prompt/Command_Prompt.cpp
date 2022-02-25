// Command_Prompt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <filesystem>
//#include <unistd.h>

#define BUFSIZE 4096
#define LONG_DIR_NAME TEXT("c:\\longdirectoryname")

using namespace std;
//using std::filesystem::current_path;
using std::string;

/*
#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");
TCHAR szMsg[] = TEXT("Message from first process.");

typedef struct VARIABLES
{

}variables_t;
#pragma pack()

extern "C"
{
    __declspec(dllexport) int function(void* variables)
    {

    }
}*/

int main(int argc, TCHAR* argv[])
{
    ///
    /*HANDLE hMapFile;
    LPCTSTR pBuf;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // use paging file
        NULL,                    // default security
        PAGE_READONLY,           // read/write access
        0,                       // maximum object size (high-order DWORD)
        BUF_SIZE,                // maximum object size (low-order DWORD)
        szName);                 // name of mapping object

    if (hMapFile == NULL)
    {
        _tprintf(TEXT("Could not create file mapping object (%d).\n"),
            GetLastError());
        return 1;
    }
    pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
        FILE_MAP_ALL_ACCESS, // read/write permission
        0,
        0,
        BUF_SIZE);

    if (pBuf == NULL)
    {
        _tprintf(TEXT("Could not map view of file (%d).\n"),
            GetLastError());

        CloseHandle(hMapFile);

        return 1;
    }


    CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
    _getch();

    UnmapViewOfFile(pBuf);

    CloseHandle(hMapFile);*/




    cout << "Command Window:\n";
    //string s;
    //cin >> s;
    //TCHAR NPath[MAX_PATH];
    //std::ifstream myfile(GetCurrentDirectory(MAX_PATH, NPath));




    DWORD  retval = 0;
    BOOL   success;
    TCHAR  buffer[BUFSIZE] = TEXT("");
    TCHAR  buf[BUFSIZE] = TEXT("");
    TCHAR** lppPart = { NULL };

    /*if (argc != 2)
    {
        _tprintf(TEXT("Usage: %s [file]\n"), argv[0]);
        return 0;
    }*/

    // Retrieve the full path name for a file. 
    // The file does not need to exist.

    retval = GetFullPathName(argv[1],
        BUFSIZE,
        buffer,
        lppPart);

    /*if (retval == 0)
    {
        // Handle an error condition.
        printf("GetFullPathName failed (%d)\n", GetLastError());
        return 0;
    }
    else
    */
        _tprintf(TEXT("The full path name is:  %s\n"), buffer);
        if (lppPart != NULL && *lppPart != 0)
        {
            _tprintf(TEXT("The final component in the path name is:  %s\n"), *lppPart);
        }
    //}


    // Create a long directory name for use with the next two examples.

    success = CreateDirectory(LONG_DIR_NAME,
        NULL);

    if (!success)
    {
        // Handle an error condition.
        printf("CreateDirectory failed (%d)\n", GetLastError());
        return 0;
    }


    // Retrieve the short path name.  

    retval = GetShortPathName(LONG_DIR_NAME,
        buf,
        BUFSIZE);

    if (retval == 0)
    {
        // Handle an error condition.
        printf("GetShortPathName failed (%d)\n", GetLastError());
        return 0;
    }
    else _tprintf(TEXT("The short name for %s is %s\n"),
        LONG_DIR_NAME, buf);


    // Retrieve the long path name.  

    retval = GetLongPathName(buf,
        buffer,
        BUFSIZE);

    if (retval == 0)
    {
        // Handle an error condition.
        printf("GetLongPathName failed (%d)\n", GetLastError());
        return 0;
    }
    else _tprintf(TEXT("The long name for %s is %s\n"), buf, buffer);

    // Clean up the directory.

    success = RemoveDirectory(LONG_DIR_NAME);
    if (!success)
    {
        // Handle an error condition.
        printf("RemoveDirectory failed (%d)\n", GetLastError());
        return 0;
    }




    
    
    /*char buff[FILENAME_MAX];
    DWORD dir = GetCurrentDirectoryW(0, NULL);
    string current_working_dir(buff);

    TCHAR buffer[MAX_PATH] = { 0 };
    DWORD directory = GetModuleFileName(NULL, buffer, MAX_PATH);*/
    ofstream myfile;
    myfile.open(*lppPart);





    system("pause");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
