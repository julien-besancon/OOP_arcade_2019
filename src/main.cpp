#include <dlfcn.h>
#include <stdio.h>
#include "Core.hpp"


IGame *init_game(std::string lib)
{
    void* handle = dlopen(lib.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        exit (84);
    }
    IGame *(*create) (void);
    *(void **) (&create) = dlsym(handle, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol" << dlsym_error << std::endl;
        dlclose(handle);
        exit (84);
    }
    IGame *game = create();
    //dlclose(handle);
    return game;
}

IGraph *init_graph(std::string lib)
{
    void* handle = dlopen(lib.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        exit (84);
    }
    IGraph *(*create) (void);
    *(void **) (&create) = dlsym(handle, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol" << dlsym_error << std::endl;
        dlclose(handle);
        exit (84);
    }
    IGraph *graph = create();
    //dlclose(handle);
    return graph;
}

void launch_game(Core core)
{
    char c = core.game->game_loop(core.graph);
    if (c == 'r')
        launch_game(core);
    if (c == 'n') {
        core.next_game();
        launch_game(core);
    }
    if (c == 'p') {
        core.prev_game();
        launch_game(core);
    }
}

int main(int ac, char **av)
{
    Core core;
    core.game = init_game(core.game_lib_name[0]);
    core.graph = init_graph(core.graph_lib_name[ac - 1]);
    launch_game(core);
    
    //graph->display();
}