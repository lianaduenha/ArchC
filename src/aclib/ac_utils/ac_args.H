
#ifndef __AC_ARGS__
#define __AC_ARGS__


#include <systemc.h>
#include <map>





typedef struct {
    int size;
    char **app_args;
    char *app_filename;
#ifdef USE_GDB
    unsigned gdb_port = 5000;
#endif
} args_t;

extern char *appfilename;
extern std::map<std::string, std::ofstream *> ac_cache_traces;

#define AC_ERROR(msg) std::cerr << "ArchC ERROR: " << msg << '\n'

void ac_init_opts(int ac, char *av[]);
args_t ac_init_args(int ac, char *av[]);



#endif // __AC_ARGS__
