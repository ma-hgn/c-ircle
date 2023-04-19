#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define X_STRETCH_FACTOR 2

#define FILL_CHAR '#'
#define EMPTY_CHAR ' '

float min(float a, float b) { return a < b ? a : b; }

int draw_circle(uint16_t width, uint16_t height) {
    float cx = (float)width / 2;
    float cy = (float)height / 2;

    float r = min((float)width / 2, (float)height / 2) - 1;

    for (int _y = 0; _y < height; _y++) {
        for (int _x = 0; _x < width; _x++) {
            int x = (int)((float)_x - cx);
            int y = (int)((float)_y - cy);

            bool fill = x * x + y * y <= r * r;
            for (int i = 0; i < X_STRETCH_FACTOR; i++) {
                printf("%c", fill ? FILL_CHAR : EMPTY_CHAR);
            }
        }
        printf("%c", '\n');
    }

    return 0;
}

