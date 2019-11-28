#include "LibraryWrapper.h"

LibraryWrapper::LibraryWrapper(const LibraryWrapper& that) {

    operator=(that);

}

LibraryWrapper::LibraryWrapper(std::string filename) : filename(filename) {

    Load();

}

LibraryWrapper::~LibraryWrapper() {

    Unload();

}

LibraryWrapper& LibraryWrapper::operator=(const LibraryWrapper &that) {

    if (this != &that) {

        this->filename = that.filename;

        if (!filename.empty()) {
            Load();
        }

    }

    return *this;

}

void* LibraryWrapper::GetFunction(std::string name) {

#ifdef AE_OS_WINDOWS
    auto func = (void*)GetProcAddress((HINSTANCE)handle, name.c_str());
#else
    auto func = dlsym(handle, name.c_str());
#endif
    if (!func) {
        throw AtlasException("Unable to load function");
    }

    return func;

}

void LibraryWrapper::Load() {

#ifdef AE_OS_WINDOWS
    handle = LoadLibrary(filename.c_str());
#else
    handle = dlopen(filename.c_str(), RTLD_LAZY);
#endif
    if (!handle) {
        throw AtlasException("Unable to load library");
    }

}

void LibraryWrapper::Unload() {

#ifdef AE_OS_WINDOWS
    FreeLibrary((HINSTANCE)handle);
#else
    dlclose(handle);
#endif

}