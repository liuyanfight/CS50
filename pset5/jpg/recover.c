/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 * 2014-7-21
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCKSIZE 512
int main(int argc, char* argv[])
{
    // TODO
    // Open memory card file
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", "card.raw");
        return 1;
    }
    
    // Find beginning of jpg        
    int jpgCount = 0;
    
    uint8_t buffer[BLOCKSIZE];
    FILE* outptr = NULL;
    while (fread(buffer, BLOCKSIZE, 1, inptr) > 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] == 0xe0 || buffer[3] == 0xe1))    
        {
            // Close the file, if it is opened
            if (outptr != NULL)
                fclose(outptr);
            // Open a new jpg
            char outfile[8];
            sprintf(outfile, "%03d.jpg", jpgCount);
            // strcat(outfile, ".jpg");
            outptr = fopen(outfile, "w");
            
            jpgCount++;   
            // !!!careful! here is my problem.I forgot it 
            fwrite(buffer, BLOCKSIZE, 1, outptr);
        }
        else if (jpgCount != 0)
        {
            // writen 512 bytes until new jpg is found
            fwrite(buffer, BLOCKSIZE, 1, outptr);
        }
    }
    // Delect end of file
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
