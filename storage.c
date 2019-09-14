#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/* opens the file for reading and writing, creating it if it doesn't exist. If
 * successful, returns dynamically created STORAGE obj. Else returns NULL
 */

STORAGE * init_storage(char * name)
{
    STORAGE *st = malloc(sizeof(STORAGE)); // TODO check - allocate storage on heap
    st->fd = open(name, O_RDWR | O_CREAT);
    if (st->fd == -1)  // open file was unsuccessful
    {
        perror("failed to open");
        return NULL;
    }
    else // open file successful
    {
       return st; 
    }
}
