// based on: https://stackoverflow.com/questions/2314542/listing-directory-contents-using-c-and-windows
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int listFiles(char *sDir);

/* print sizes and creation dates (according to UTC) of the files */
int main(int argc, char **argv)
{
    if(argc == 1) // you must enter a default directory
        listFiles("C:\\Windows\\");
    else
        while(--argc > 0)
            listFiles(*++argv);
    return 0;
}

/* listFiles: list all contents of directory */
int listFiles(char *sDir)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    char sPath[1024];

    ULONGLONG lSize;
    SYSTEMTIME systemTime;

    // determine file mask
    sprintf(sPath, "%s\\*.*", sDir); // *.* -> look for everything

    if((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "listFiles: path not found: [%s]\n", sDir);
        return -1;
    }
    do
    {
        // skip directory entries for itself and its parent
        if(strcmp(fdFile.cFileName, ".") != 0 && strcmp(fdFile.cFileName, "..") != 0)
        {
            // add the name of found a file/directory to the end of the path
            sprintf(sPath, "%s\\%s", sDir, fdFile.cFileName);

            // get size and creation date of the file
            lSize = (ULONGLONG)(fdFile.nFileSizeHigh * (MAXDWORD+1)) + fdFile.nFileSizeLow;
            FileTimeToSystemTime(&fdFile.ftCreationTime, &systemTime);

            // print
            printf("%2d/%2d/%4d, %2d:%2d:%2d; ", systemTime.wDay, systemTime.wMonth, systemTime.wYear,
                       systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
            printf("%8ld %s\n", lSize, sPath);

            // directory or file?
            if(fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // directory
                listFiles(sPath); // recursion
        }
    }
    while(FindNextFile(hFind, &fdFile)); // look for next file
    FindClose(hFind); // close

    return 0;
}
