
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
//#define MAX_ARGS 3;
//#define INBUFFSIZE 128;   // size of buffer in bytes


const char SEPARATORS[] = " \t\n";
char in_buffer[200];           // Input buffer from STDIN. command input buffer INBUFFSIZE = 200
char * args[100];               // the arguments split up
char ** arg;                 // working pointer that steps through the args
char charBuffer[128];             // the 128 byte buffer that holds all input numbers


void list()
{
            /*
    for (int k=0; k<128; k++)       // testing charbuffer
    {
        charBuffer[k] = 0;
    }
             */
    for (int j=0; j<8; j++)
    {
        for (int i=0; i<16; ++i)    // print first 16 char array spots
        {
            printf("%02x", charBuffer[j*16+i]);
        }
        printf("\n");
    }
}

void zero()
{
    for (int i=0; i<128; i++)
    {
        charBuffer[i] = 0;
    }
}

void writeByte(char** args)   // set the specified byte to input value
{
    // TODO: error checking for number of args.
    int* location = (int*) *args;       // will grab the next 4 bytesfor an int
    args++;
    charBuffer[*location] = **args;
    
}

void readByte(char** arg)
{
    
}
void writeHex(char** arb)
{
    
}

void writeChar(char** arg)
{
    
}

void readHex(char** arg)
{
    
}

void readChar(char** arg)
{
    
}

void writeInt(char** arg)
{
    
}

void readInt(char** arg)
{
    
}

void writeFloat(char** arg)
{
    
}

void readFloat(char** arg)
{
    
}

void writeString(char** arg)
{
    
}

void readString(char** arg)
{
    
}

void writeToFile(char** arg)
{
    
}

void readFileToBuf(char** arg)
{
    
}

                 
int main(int argc, const char * argv[])
{
    while(fgets(in_buffer, 100, stdin)!= NULL) // TODO: check         MAX_ARGS
    {
        arg = args;
        *arg++ = strtok(in_buffer,SEPARATORS);   // tokenize input
        while ((*arg++ = strtok(NULL,SEPARATORS)));
        arg++;
        switch(*arg[0])
        {
            case 'l' :  list();
                break;
            case 'z' :  zero();
                break;
            case 'b' : writeByte(arg);
                break;
            case 'B' : readByte(arg);
                break;
            case 'h' : writeHex(arg);
                break;
            case 'H' : readByte(arg);
                break;
            case 'c' : writeChar(arg);
                break;
            case 'C' : readChar(arg);
                break;
            case 'i' : writeInt(arg);
                break;
            case 'I' : readInt(arg);
                break;
            case 'f' : writeFloat(arg);
                break;
            case 'F' : readFloat(arg);
                break;
            case 's' : writeString(arg);
                break;
            case 'S' : readString(arg);
                break;
            case 'w' : writeToFile(arg);
                break;
            case 'r' : readFileToBuf(arg);
                break;

        }
        return 0;
    }
}
