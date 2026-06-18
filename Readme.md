
## Multi-Channel ADC Thermal Monitor
This project demonstrates the transition from a standard high-level C implementation using strings to an efficient Embedded C implementation using direct pointer arithmetic to monitor machine temperatures.
## The Code Evolution## 
1. String-Based Approach (High Overhead)

* How it worked: Stored raw hex data as string text ("0x0A20") and parsed it at runtime using strtol().
* Problem: Text arrays and string-parsing libraries are too heavy, slow, and consume excessive memory for resource-constrained microcontrollers.

## 2. Pointer-Based Approach (Embedded Optimized)

* How it works: Replaces text strings with an array of raw numbers (uint16_t) mapping directly to hardware memory.
* Optimization: Navigates the memory address block dynamically using explicit pointer-offset scaling (*(ptr + i)).
* Benefit: Zero runtime overhead, minimal binary size, and faster memory reads.

------------------------------
## Technical Comparison

| Feature | Original Code | Optimized Embedded Code |
|---|---|---|
| Data Format | 2D Character Array (char[][]) | 16-bit Integer Array (uint16_t[]) |
| Memory Extraction | Standard Library strtol() | Direct Pointer Dereferencing *(ptr + i) |
| Hardware Fit | Poor (High CPU/RAM usage) | Perfect (Simulates DMA/ADC registers) |

------------------------------
## Expected Output
Both programs correctly identify the overheating threshold fault at Zone 3:

Processing ZONE1 (0x0A20 / 2592) safely.
Processing ZONE2 (0x0B00 / 2816) safely.
[WARNING] ZONE3 (0x0E50 / 3664) exceeds MAX_SAFE! Skipping...
Processing ZONE4 (0x09F0 / 2544) safely.

------------------------------
 
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
