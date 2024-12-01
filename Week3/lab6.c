#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point_t;

typedef struct circle {
    point_t center;
    double radius;
} circle_t;

// Hàm kiểm tra xem hai hình tròn có giao nhau không
int two_circle(circle_t *c1, circle_t *c2) {
    double distance_squared = (c1->center.x - c2->center.x) * (c1->center.x - c2->center.x) +
                              (c1->center.y - c2->center.y) * (c1->center.y - c2->center.y);
    double radius_sum = c1->radius + c2->radius;
    return distance_squared <= (radius_sum * radius_sum);
}

int main() {
    int N;
    scanf("%d", &N);

    circle_t *circles = (circle_t *)malloc(N * sizeof(circle_t));
    if (circles == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%lf %lf %lf", &circles[i].center.x, &circles[i].center.y, &circles[i].radius) ;
        }

    int max = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if ( i!=j && two_circle(&circles[i], &circles[j])) {
                count++;
            }
        }
        if (count > max) max = count;
    }
    printf("%d\n", max);
    free(circles);

    return 0;
}
