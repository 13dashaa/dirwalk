#ifndef DIRWALK_H
#define DIRWALK_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_ENTRIES 1024

void walk_dir(const char *dir_path, int show_links, int show_dirs, int show_files, int sort);
void process_entry(const char *dir_path, struct dirent *entry, int show_links, int show_dirs, int show_files, int sort);

#endif