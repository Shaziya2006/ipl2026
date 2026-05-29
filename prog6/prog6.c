#include <stdio.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 20

// Function 1: Initialize buffer
void initializeBuffer(char buffer[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            buffer[i][j] = ' ';
        }
    }
}

// Function 2: Draw circle into buffer
void drawCircle(char buffer[HEIGHT][WIDTH], int centerX, int centerY, int radius) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            int dx = x - centerX;
            int dy = y - centerY;

            // Circle equation
            if (dx * dx + dy * dy <= radius * radius) {
                buffer[y][x] = '*';
            }
        }
    }
}

// Function 3: Display buffer
void printBuffer(char buffer[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", buffer[i][j]);
        }
        printf("\n");
    }
}

// Function 4: Main controller
int main() {
    char buffer[HEIGHT][WIDTH];

    initializeBuffer(buffer);

    drawCircle(buffer, WIDTH / 2, HEIGHT / 2, 8);

    printBuffer(buffer);

    return 0;
}