#include <stdio.h>


struct point
{
    int x, y;
};

void point_init_default(struct point* self)            // <--- "constructor" in C
{
    self->x = 0;
    self->y = 0;
}

int /*bool*/ point_equal(struct point lhs, struct point rhs)
{
    return
        lhs.x == rhs.x &&
        lhs.y == rhs.y;
}
int /*bool*/ point_not_equal(struct point lhs, struct point rhs)
{
    return ! point_equal(lhs, rhs);
}

void point_move(struct point* self, int x, int y)
{
    self->x += x;
    self->y += y;
}

struct point point_add(struct point lhs, struct point rhs)
{
    struct point sum;
    sum.x = lhs.x + rhs.x;
    sum.y = lhs.y + rhs.y;
    return sum;
}

struct point point_sub(struct point lhs, struct point rhs)
{
    struct point diff;
    diff.x = lhs.x - rhs.x;
    diff.y = lhs.y - rhs.y;
    return diff;
}

void point_print(struct point p)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
    printf("(%d, %d)", p.x, p.y);
#pragma GCC diagnostic pop
}


int main()
{
    {
        struct point p;                                   // <--- uninitialized
        printf("uninitialized: ");
        point_print(p);
        printf("\n");
    }

    {
        struct point p = {1,2};                           // <--- C struct initialization
        printf("struct-initialized: ");
        point_print(p);
        printf("\n");
    }

    {
        struct point p;
        point_init_default(&p);
        printf("'default'-initialized: ");
        point_print(p);
        printf("\n");
    }

    {
        const struct point p = {1,2};
        const struct point q = {3,4};

        printf("equal: ");
        point_print(p);
        printf(" == ");
        point_print(q);
        printf(": ");
        printf("%d\n", point_equal(p, q));
    }
    
    {
        const struct point p = {1,2};
        const struct point q = {3,4};

        printf("not equal: ");
        point_print(p);
        printf(" != ");
        point_print(q);
        printf(": ");
        printf("%d\n", point_not_equal(p, q));
    }

    {
        struct point p = {1,2};
        printf("original: ");
        point_print(p);
        printf(", moved by (3, 4): ");
        point_move(&p, 3, 4);
        point_print(p);
        printf("\n");
    }

    {
        const struct point p = {1,2};
        const struct point vec = {3,4};

        const struct point sum = point_add(p, vec);
        printf("added: ");
        point_print(sum);
        printf("\n");

        const struct point diff = point_sub(p, vec);
        printf("subbed: ");
        point_print(diff);
        printf("\n");
    }

    return 0;
}
