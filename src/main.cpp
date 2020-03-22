#include <iostream>
#include <dlfcn.h>
#include <stdio.h>

int main() {
    std::cout << "C++ dlopen demo\n\n";

    // open the library
    std::cout << "Opening hello.so...\n";
    void* handle = dlopen("./lib_arcade_sfml.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        return 1;
    }

    // load the symbol
    std::cout << "Loading symbol hello...\n";

    // reset errors
    dlerror();
    void (*hello) ();
    //hello = dlsym(handle, "hello");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'hello': " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }

    // use it to do the calculation
    std::cout << "Calling hello...\n";
    hello();

    // close the library
    std::cout << "Closing library...\n";
    dlclose(handle);
}