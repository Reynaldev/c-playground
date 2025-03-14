#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int n = 1024256;  // Your integer
    char buffer[2];           // Buffer to hold the first 2 bytes

    // Copy the first 2 bytes of the integer into the buffer
    // Assuming little-endian system
    buffer[0] = (n & 0xFF);            // Low byte
    buffer[1] = (n >> 8) & 0xFF;       // Second byte

    // Print the integer information
    printf(
        "Integer | %p\n"
        "Value\t%i\n"
        "Size\t%lu\n"
        "Hex\t%x\n",
        &n,
        n,
        sizeof(n),
        n
    );

    // Print the buffer information
    printf(
        "\nBuffer | %p\n"
        "Text\t%c%c\n"
        "Value\t%02X %02X\n"
        "Size\t%lu\n",
        (void*)buffer,
        (unsigned char)buffer[0],
        (unsigned char)buffer[1],
        sizeof(buffer)
    );

    // Open the file for writing
    FILE *file = fopen("copy_bytes.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    // Write the first 2 bytes to the file
    fwrite(buffer, 1, 2, file);

    // Close the file
    fclose(file);
    
    return 0;
}
