#include <stdio.h>
#include <stdint.h>

#define MAX_SAFE 3072 // 0x0C00 in decimal

int main()
{
   
    uint16_t zone_data[4] = {0x0A20, 0x0B00, 0x0E50, 0x09F0};
    uint16_t *ptr = zone_data; 

    for (int i = 0; i < 4; i++)
    {
        uint16_t current_reading = *(ptr + i);

        if (current_reading > MAX_SAFE)
        {
           
            printf("[WARNING] ZONE%d (0x%04X / %u) exceeds MAX_SAFE! Skipping...\n", 
                   i + 1, current_reading, current_reading);
            continue;
        }
        printf("Processing ZONE%d (0x%04X / %u) safely.\n", 
               i + 1, current_reading, current_reading);
    }
    
    return 0;
}
