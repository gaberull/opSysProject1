// Austin "Gabe" Scott      project1
//  version 9/13/19

/* the main program maintains a 128-byte buffer in memory. 
 * The user can interact with this buffer by placing integer, 
 * floating point, character, string and hexadecimal values at 
 * a specified location in the buffer. In addition, the user may 
 * request that the values in the buffer be placed in a specified 
 * location in the storage file, or that the buffer values can be read 
 * from a specific location in the file.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_ARGS = 3;
#define INBUFFSIZE = 128;   // size of buffer in bytes


const char SEPARATORS[] = " \t\n";
char in_buffer[INBUFFSIZE];           // Input buffer from STDIN. command input buffer
char * args[MAX_ARGS];               // pointers to arg strings
char ** arg;                 // working pointer that steps through the args

int list()
{
    
}

int zero()
{

}

int writeByte(char* arg)   // set the specified byte to input value
{
    
}

int readByte(char* arg)
{
    
}

int writeHexByte(

int main(int argc, const char * argv[])
{
    while(fgets(in_buffer, MAX_ARGS, stdin)!= NULL)
    {
        arg = args;
        *arg++ = strtok(in_buffer,SEPARATORS);   // tokenize input  
        while ((*arg++ = strtok(NULL,SEPARATORS)));
        switch(arg[0])
        {
            case 'l': list(); 
                      break;
            case 'z': zero();
                      break;
            case 'b': writeByte(arg);
                      break;
            case 'B': readByte(arg);
                      break;
            case 'h': writeHexByte(arg);
                        break;
                      case 'H

        }

    return 0;
}
