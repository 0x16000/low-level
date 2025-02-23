#ifndef TYPES_H_
#define TYPES_H_

#include <stdio.h>

void Option() {
    printf("==============================\n");
    printf("=                            =\n");
    printf("=                            =\n");
    printf("=         Low Level          =\n");
    printf("=                            =\n");
    printf("=                            =\n");
    printf("==============================\n");

    int input;

    printf("1: Show size of RAM\n");

    printf("\n");

    printf("2: Show CPU information\n")M

    printf("\n");

    printf("Enter your Choice: ");
    scanf("%d", &input);

    if (input == 1) {  // Fix 'choice' to 'input'
        FILE *fp = fopen("/proc/meminfo", "r");
        if (fp != NULL) {
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), fp)) {
                if (sscanf(buffer, "MemTotal: %s", buffer) == 1) {
                    printf("Total RAM: %s\n", buffer);
                    break;
                }
            }
            fclose(fp);  // Move fclose() inside the if block
        } else {
            printf("Unable to read memory.\n");
        }
    } else if (input == 2) {
        // Show CPU info from /proc/cpuinfo
        FILE *fp = fopen("/proc/cpuinfo", "r");
        if (fp == NULL) {
            perror("Error opening /proc/cpuinfo");
            return;  // Exit the function if CPU info can't be opened
        }

        char buffer[256];
        int found_cpu = 0;

        while (fgets(buffer, sizeof(buffer), fp)) {
            // Only print the first occurrence of the CPU model name
            if (strncmp(buffer, "model name", 10) == 0 && !found_cpu) {
                printf("CPU Info: %s", buffer);
                found_cpu = 1;  // Stop after finding the first CPU model name
            }
        }
        fclose(fp);  // Close file after reading
    } else {
        printf("Invalid choice.\n");
    }
}


// Define the clear function outside Option()
void clear() {
    printf("\e[H\e[2J");
}

#endif // TYPES_H_
