#include <stdio.h>

int main() {
    int x = 0x0e;
    int mask = 0x01;
    unsigned char m_and = x & mask;
    unsigned char m_or = x | mask;
    unsigned char m_land = x && mask;
    unsigned char m_lor = x || mask;
    printf("0x%02x 0x%02x 0x%02x 0x%02x\n", m_and, m_or, m_land, m_lor);
}
