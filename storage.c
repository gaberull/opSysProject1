#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "storage.h"

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

/* closes the previously opened file. Frees dynamically allocated structure
 * Returns 0 on success and -1 on failure
 */
int close_storage(STORAGE *storage)
{
    free();
    return close(storage->fd)
}

/*
 * reads len num of bytes into buf starting with offset location. Returns
 * number of bytes read. 0 if at EOF or a negative num on error. 
 */
int get_bytes(STORAGE *storage, unsigned char *buf, int location, int len)
{
   // TODO implement this
}
