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
    }
}

// Define the clear function outside Option()
void clear() {
    printf("\e[H\e[2J");
}

#endif // TYPES_H_
