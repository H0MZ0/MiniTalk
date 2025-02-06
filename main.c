#include <stdio.h>
int main()
{
    char c = 'h'; // ASCII 65 = 01000001 in binary
    for (int i = 7; i >= 0; i--)
    {
        int bit = (c >> i) & 1; // Extract the i-th bit
        printf("%d", bit); // Print or send the bit
    }
}