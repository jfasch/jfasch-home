#include <math.h>
#include <stdio.h>

struct point
{
    int x;
    int y;
};

double distance_from_origin(const struct point* p)
{
    return sqrt(p->x*p->x + p->y*p->y);
}

void move_point(struct point* p, int x, int y)
{
    p->x += x;
    p->y += y;
}

struct point add_points(
    struct point lhs,
    struct point rhs)
{
    struct point sum;
    sum.x = lhs.x + rhs.x;
    sum.y = lhs.y + rhs.y;
    return sum;
}

int main(void)
{
    struct point A = {1,2}, B = {2,4};   // C struct initialization
    struct point C, D;  // <--- uninitialized! HERE BE DRAGONS!
    double distance;

    C = A; // struct assignment

    distance = distance_from_origin(&A);
    printf("|A|: %lf\n", distance);

    // pass A and B as pararameters *by copy*, and return (and assign to C) *by copy*
    D = add_points(A, B);
    printf("D.x: %d, D.y: %d\n", D.x, D.y);

    move_point(&C, 2, 3);
    printf("C.x: %d, C.y: %d\n", C.x, C.y);

    return 0;
}
