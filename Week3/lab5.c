#include <stdio.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point_t;

typedef struct circle {
    point_t center;
    double radius;
} circle_t;

int is_in_circle(point_t *p, circle_t *c) {
    double distance_squared = (p->x - c->center.x) * (p->x - c->center.x) +
                              (p->y - c->center.y) * (p->y - c->center.y);
    
    return distance_squared < c->radius * c->radius; 
}

int main() {
    point_t p;
    circle_t c;
    
    scanf("%lf %lf %lf", &c.center.x, &c.center.y, &c.radius);
    scanf("%lf %lf", &p.x, &p.y);
    
    if (is_in_circle(&p, &c)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
