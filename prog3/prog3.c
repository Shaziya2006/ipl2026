#include <stdio.h>

void printBits(int n) {
    for (int i = sizeof(int)*8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}
int countOnes(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int x = 8;
    printBits(x); 
    int result= countOnes(x);
  printf("count of 1 bit %d",result);
}