#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SAFE 3072 // 0x0C00
int main()
{
    int i;
    char ZONE[4][7] =
        {

            "0x0A20",
            "0x0B00",
            "0x0E50",
            "0x09F0"};

    for (i = 0; i < 4; i++)
    {
        unsigned int decimal = (unsigned int)strtol(ZONE[i], NULL, 16);
        if (decimal > MAX_SAFE)
        {
            printf("[WARNING] ZONE%d (%s / %u) exceeds MAX_SAFE! Skipping...\n", i + 1, ZONE[i], decimal);
            continue;
        }
        printf("Processing ZONE%d (%s / %u) safely.\n", i + 1, ZONE[i], decimal);
    }
    return 0;
}
