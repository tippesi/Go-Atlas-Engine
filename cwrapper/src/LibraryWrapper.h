#ifndef LIBRARYWRAPPER_H
#define LIBRARYWRAPPER_H

#include <System.h>

class LibraryWrapper {

public:
    LibraryWrapper() {}

    LibraryWrapper(const LibraryWrapper& that);

    LibraryWrapper(std::string filename);

    ~LibraryWrapper();

    LibraryWrapper& operator=(const LibraryWrapper& that);

    void* GetFunction(std::string name);

private:
    void Load();

    void Unload();

    std::string filename;
    void* handle;


};

#endif