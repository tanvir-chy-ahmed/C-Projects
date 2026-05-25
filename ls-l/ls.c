#include <stdio.h>
#include <dirent.h> // directory stream manipulation
#include <sys/stat.h> // Provides file information functions and structures.
#include <string.h>
#include <time.h>

int main()
{
    DIR *dir;
    
    struct dirent *entry; // readdir() owns memory
    struct stat file_stat; // YOU own memory
    /*
        Pointer struct use ->
        Normal struct use .
    */
    
    char time_str[20];
    int total_files = 0;


    dir = opendir("."); // . mean current directory

    if(dir == NULL)
    {
        perror("ls");
        return 1;
    }

    printf("Name\t\tSize\t\tModified\t\tType\n");
    printf("____\t\t____\t\t________\t\t____\n\n");

    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0 ) // .. parent dir
        continue;
        
        if(stat(entry->d_name,&file_stat) == 0)
        {
            strftime(time_str,sizeof(time_str),"%Y-%m-%d %H:%M",localtime(&file_stat.st_mtime));
            printf("%-15s\t",entry->d_name);
            printf("%-8ld\t",(long)file_stat.st_size);
            printf("%s\t",time_str);
        
            if(S_ISDIR(file_stat.st_mode))
            {
                printf("DIR\n");
            }else if(S_ISREG(file_stat.st_mode))
            {
                printf("FILE\n");
            }else if(S_ISLNK(file_stat.st_mode))
            {
                printf("LINK\n");
            }else
                printf("OTHERS\n");
                
                
            total_files++;
            
        }
    }
   
   printf("\nTotal files: %d\n",total_files);
   closedir(dir);
   
   
   
    return 0;
}