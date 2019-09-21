
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
unsigned char charBuffer[128];             // the 128 byte buffer that holds all input numbers


void list()         // 'l' **
{
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
    for (int i=0; i<128; i++)       // iterate through whole buffer and set to zero
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

void readByte(char** arg)           // 'B'** Read byte in decimal
{
    int location = atoi(*arg);
    printf("%d\n", charBuffer[location]);       // print number in decimal
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

void writeChar(char** arg)          // 'c' TODO: check to make sure can't handle multiple bytes (2 chars) or if I need to handle that error. Also make sure it stores it in ascii. (currently printing ascii equivalent in hex)
{
    int location = atoi(*arg);
    arg++;
    charBuffer[location] = **arg;
}

void readHex(char** arg)            // 'H' prints off the value of the byte in hexadecimal
{
    int location = atoi(*arg);      // get location
    printf("%x\n", charBuffer[location]);   // print value off in hex
}

void readChar(char** arg)       // 'C' Read character value (glyph) TODO: See if need to copy it out like readInt
{
    int location = atoi(*arg);      // grab int location in buffer
    arg++;                  // increment counter to next argument
    printf("%c\n", charBuffer[location]); // print character value
    
}

void writeInt(char** arg)       // 'i'** write an integer value to buffer location. Stores over how ever many bytes are required.
{
    int location = atoi(*arg);
    arg++;
    //long int num = strtol(*arg, 0,16);
    int toStore = atoi(*arg);
    unsigned char* ptr = &charBuffer[location];
    memcpy(ptr, &toStore, sizeof(toStore));
}

void readInt(char** arg)        // 'I'**
{
    int location = atoi(*arg);      // get location
    arg++;
    
    int result=0;
    unsigned char* ptr = &charBuffer[location];
    memcpy(&result, ptr, sizeof(result));
    
    printf("%d\n", result);
                                                        /*
    int toStore = atoi(*arg);
                                                         */
}

void writeFloat(char** arg)         // 'f'
{
    int location = atoi(*arg);      // get location
    arg++;
    
    float num = atof(*arg);         // convert number to float
    unsigned char* ptr = &charBuffer[location];
    memcpy(ptr, &num, sizeof(num));
}

void readFloat(char** arg)          // 'F'
{
    int location = atoi(*arg);
    arg++;
    
    float result = 0.0;
    unsigned char* ptr = &charBuffer[location];
    memcpy(&result, ptr, sizeof(result));
    printf("%f\n", result);
}

void writeString(char** arg)            // 's'      // TODO: needs testing
{
    int location = atoi(*arg);
    arg++;
    
    //char str[50];
    int size = (int)strlen(*arg) + 1;       // add one to size of *arg for null terminator
    char str[size];
    sscanf(*arg, "%s", str);    // use sscanf to copy string over to a new string then copy it over
    int i = 0;
    while (1)
    {
        charBuffer[location] = str[i];
        location++;
        i++;
        if (str[i] == '\0')
        {
            charBuffer[location] = '\0';    // copy over null terminating character TODO: is this necessary? It is one longer and it is null by default
            break;      // copy over until we hit null terminating character
        }
    }
}

void readString(char** arg)         // 'S'  reads string from buffer
{
    int location = atoi(*arg);
    
    while (charBuffer[location] != '\0')
    {
        printf("%c", charBuffer[location]);
        location++;
    }
    printf("\n");
}

void writeToFile(char** arg)        // 'w'
{
    
}

void readFileToBuf(char** arg)          // 'r'
{
    
}

int main(int argc, const char * argv[])
{
    while(fgets(in_buffer, 100, stdin)!= NULL) // while input string is coming in
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
            case 'H' : readHex(arg);
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
