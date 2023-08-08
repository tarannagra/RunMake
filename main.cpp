/*
    I don't particularly like C/C++ but here I am programming in it

    I chose C++ because it's a cool language and I did it previously, so like experience.
        That and so it's not always code this, that, something else in Python.
    
    The code is all over the place, 'but if it works, don't touch it'. And so I won't.
    
        Made by Taran Nagra
*/


#include <direct.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>

#define make_command "make build"
#define rootDirectory "."

void ListFilesInDirectory(const std::string& directoryPath) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((directoryPath + "\\*").c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return;
    }

    do {
        std::string fileName = findFileData.cFileName;
        if (fileName != "." && fileName != "..") {
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                std::string subDirectoryPath = directoryPath + "\\" + fileName;
                ListFilesInDirectory(subDirectoryPath);
            } else {
                if (fileName == "Makefile") {
                    _chdir(directoryPath.c_str());
                    system(make_command);
                    _chdir("../");
                }
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

int main(int argc, char** argv) {
    ListFilesInDirectory(rootDirectory);
    std::cout << "Ran each of the Makefiles :D.\n";
    return 0;
}
