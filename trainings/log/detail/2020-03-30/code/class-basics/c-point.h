#ifndef __HAVE_C_POINT_H__
#define __HAVE_C_POINT_H__

#ifdef __cplusplus
extern "C" {
#endif

struct point
{
    int x;
    int y;
};

// note the use of "const" with parameter "by": we promise to not
// modify it, although we receive a pointer.
extern void point_move(struct point* self, const struct point* by);

// add() is supposed to add p and by, and make a new point. hence the
// "const" with the parameters.
extern struct point point_add(const struct point* p, const struct point* by);

#ifdef __cplusplus
}
#endif

#endif
