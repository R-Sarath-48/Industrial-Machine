 
 Look at Zone 1: Check if its value is bigger than 0x0C00. 
 If it is safe, move on.Jump to the Next Zones: Advance your pointer mathematically to look at Zone 2, Zone 3, and Zone 4 one by one.
 Sound the Alarm: If you find any zone that is over the limit, you must flip a specific switch (a bit flag) to tell the main computer exactly which zone is melting down so it can trigger an emergency shutdown.
 
 
 [Zone 1 Sensor]    [Zone 2 Sensor]    [Zone 3 Sensor]    [Zone 4 Sensor]
        │                  │                  │                  │
        └──────────────────┴─────────┬────────┴──────────────────┘
                                     ▼
                        [Microcontroller Chip (MCU)]
                                     │
                 (Reads values and saves them into Memory)
                                     │
                                     ▼
                        [RAM Memory Block (Array)]
               ┌──────────┬──────────┬──────────┬──────────┐
               │  Zone 1  │  Zone 2  │  Zone 3  │  Zone 4  │
               │  0x0A20  │  0x0B00  │  0x0E50  │  0x09F0  │
               └──────────┴──────────┴──────────┴──────────┘
                     ▲
                     │
               [Your Pointer] ───► Moves step-by-step to check each zone
