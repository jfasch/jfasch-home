#include "c-point.h"


struct point point_create(int x, int y)
{
    struct point ret;
    ret.x = x;
    ret.y = y;
    return ret;
}

void point_move(struct point* self, struct point addend)
{
    self->x += addend.x;
    self->y += addend.y;
}

struct point point_add(struct point p, struct point q)
{
    struct point ret;
    ret.x = p.x + q.x;
    ret.y = p.y + q.y;
    return ret;
}

int /*bool*/ point_compare(struct point p, struct point q)
{
    return p.x == q.x && p.y == q.y; // memcmp()?
}
