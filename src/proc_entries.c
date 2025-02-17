#include "dirwalk.h"
#include <limits.h> 
void process_entry(const char *path, struct dirent *entry, int show_links, int show_dirs, int show_files, int sort){
    char fullpath[1024];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

    struct stat statbuf;
    if (stat(fullpath, &statbuf) == -1) {
        perror("stat");
        return;
    }
    int dir = S_ISDIR(statbuf.st_mode);
    int link = S_ISLNK(statbuf.st_mode);
    int file = S_ISREG(statbuf.st_mode);

    if ((show_links && link) || (show_dirs && dir) || (show_files && file)) {
        printf("%s\n", fullpath);
    }

    if (dir) {
        walk_dir(fullpath, show_links, show_dirs, show_files, sort);//recursion
    }



}
