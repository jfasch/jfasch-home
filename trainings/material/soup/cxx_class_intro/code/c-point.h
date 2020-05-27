#ifndef __HAVE_C_POINT_H__
#define __HAVE_C_POINT_H__

struct point
{
    int x;
    int y;
};

#ifdef __cplusplus
extern "C" {
#endif

struct point point_create(int x, int y);
void point_move(struct point* self, struct point addend);
struct point point_add(struct point p, struct point q);
int /*bool*/ point_compare(struct point p, struct point q);

#ifdef __cplusplus
}
#endif

#endif
