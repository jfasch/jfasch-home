#include "c-point.h"


void point_move(struct point* self, const struct point* by)
{
    self->x += by->x;
    self->y += by->y;
}

struct point point_add(const struct point* p, const struct point* by)
{
    struct point result = *p;
    point_move(&result, by);
    return result;
}
