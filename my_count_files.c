#include <stdio.h>
#include <string.h>
#include <dirent.h>

// Write a command line that counts and displays the number of regular files and directories in the current directory and all its sub-directories. 
// It should include ".", the starting directory.

int count_files(const char *dir_path)
{
    DIR *dir = opendir(dir_path);
    if (dir == NULL) 
    {
        return -1;
    }
    
    struct dirent* entity;
    entity = readdir(dir);
    int files= 0;

    int regular_files = 0;
    int directories = 0;

    while (entity != NULL) 
    {   
        // printf("%hhd %s %d\n", entity->d_type, entity->d_name, files);
        if (entity->d_type == DT_REG) // entity type = regular files!
        { 
            regular_files++;

            // printf("%hhd %s reg %d\n", entity->d_type, entity->d_name, regular_files);
        }
        else if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0)  // entity type = directory !
        {
            directories++;
            // printf("%hhd %s dir %d\n", entity->d_type, entity->d_name, directories);
            char path[100] = {0};
            strcat(path, dir_path);
            strcat(path, "/");
            strcat(path, entity->d_name);

            directories += count_files(path);
        
        }
        entity = readdir(dir);

        files = regular_files + directories;

    }

    closedir(dir);
    return files;
}

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("%d\n", count_files("."));
    } 
    else 
    {
        printf("%d", count_files(argv[1]));
    }

    return 0;
}