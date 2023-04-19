#include "circle.h"
#include <stdio.h>

int main(void) {
    int width = 15, height = 15;

    printf("Please enter WIDTH, HEIGHT:\n");
    scanf("%d %d", &width, &height);

    draw_circle(width, height);

    return 0;
}
