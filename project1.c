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


int main(argc, 
