
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


void list()         // 'l' **
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
            printf("%02x ", charBuffer[j*16+i]);       // row major ordering
        }
        printf("\n");
    }
}

void zero()         // 'z'** zeroes out entire buffer
{
    for (int i=0; i<128; i++)
    {
        charBuffer[i] = 0;
    }
}

void writeByte(char** arg)   // 'b'** set the specified byte to input value
{
    // TODO: error checking for number of args.
    int location = atoi(*arg);       // atoi() converts char buffer to int
    arg++;
    charBuffer[location] = atoi(*arg); // convert char array at *arg to int
}

void readByte(char** arg)           // 'B'**
{
    int location = atoi(*arg);
    printf("%d\n", charBuffer[location]);
}
void writeHex(char** arg)               // 'h'
{
    int location = atoi(*arg);
    arg++;                      // move arg to next number
    // call charToHex function before writing to buffer
    
    long int num = strtol(*arg, 0,16); // convert string to long, tell it the values in that string are in hexadecimal
    //char first = (*arg)[0];//**arg;
    //char second = (*arg)[1]; //*(*arg+1);
        charBuffer[location] = num;
}

void writeChar(char** arg)          // 'c'
{
    
}

void readHex(char** arg)            // 'H'
{
    
}

void readChar(char** arg)       // 'C'
{
    
}

void writeInt(char** arg)       // 'i'** write an integer value to buffer location. Stores over how ever many bytes are required.
{
    int location = atoi(*arg);
    arg++;
    //long int num = strtol(*arg, 0,16);
    int toStore = atoi(*arg);
    char* ptr = &charBuffer[location];
    memcpy(ptr, *arg, sizeof(toStore));
    
        /*
    
    int num = atoi(*arg)
    //long int num = strtol(*arg, 0,16);
    int input[sizeof(num)];
    sprintf(input, "%02x", num);
    
    char* spotInMem = &charBuffer[location];
    long int num = strtol(*arg, 0,16);
    int numdigits = log10(num) + 1;
    char s[numdigits];
    sscanf(*arg, %02x, charBuffer[location]);
    sprintf(s, %x02, num);
    memcpy(spotInMem, *arg, strlen(*arg));
                 */               /*
    int location = atoi(*arg);
    arg++;
    
    long int num = strtol(*arg, 0,16);  // convert character to hex
    
    int size = sizeof(num);
    int numDigits = log10(num) + 1;     // get number of digits in num
    if (!(numDigits%2))                   // If odd number of digits append a zero
    //charBuffer[location] = num;
                                 */
}

void readInt(char** arg)        // 'I'**
{
    
    int location = atoi(*arg);      // get location
    arg++;
    printf("%d", charBuffer[location]);
}

void writeFloat(char** arg)         // 'f'
{
    
}

void readFloat(char** arg)          // 'F'
{
    
}

void writeString(char** arg)            // 's'
{
    
}

void readString(char** arg)         // 'S'
{
    
}

void writeToFile(char** arg)        // 'w'**
{
    
}

void readFileToBuf(char** arg)          // 'r'
{
    
}

                 
int main(int argc, const char * argv[])
{
    while(fgets(in_buffer, 100, stdin)!= NULL) // TODO: check         MAX_ARGS
    {
        arg = args;                 // arg is like an iterator through string of arguments (args)
        *arg++ = strtok(in_buffer,SEPARATORS);   // tokenize input
        while ((*arg++ = strtok(NULL,SEPARATORS)));
        arg = args;
        char option = **arg;
        arg++;
        
        switch(option)
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
    }
    return 0;
}
                                                     
