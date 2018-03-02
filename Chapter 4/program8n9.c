#include <stdio.h>
#include <math.h>

struct point{
    int x, y;
};

struct rect{
    struct point ne, se, sw, nw;
};

int distance(struct point p1, struct point p2){
    return (int) pow(pow(p1.x - p2.x, 2)+pow(p1.y - p2.y, 2), 0.5);
}

int RectArea(struct rect fig){
    return (distance(fig.ne, fig.se) * distance(fig.ne, fig.nw));
}

struct point RotatePoint(struct point p){
    struct point res;
    res.x = p.y * -1;
    res.y = p.x;
    return res;
}

void RotateRect(struct rect *fig){
    (*fig).ne = RotatePoint((*fig).ne);
    (*fig).se = RotatePoint((*fig).se);
    (*fig).sw = RotatePoint((*fig).sw);
    (*fig).nw = RotatePoint((*fig).nw);
}

int main(){
    struct point p1;
    p1.x = 0;
    p1.y = 0;
    struct point p2;
    p2.x = 0;
    p2.y = 1;
    struct point p3;
    p3.x = 2;
    p3.y = 0;
    struct point p4;
    p4.x = 2;
    p4.y = 1;
    struct rect rectangle;
    rectangle.ne = p2;
    rectangle.se = p1;
    rectangle.sw = p3;
    rectangle.nw = p4;
    RotateRect(&rectangle);

    printf("%d\n", RectArea(rectangle));
    printf("%d %d\n", rectangle.nw.x, rectangle.nw.y);
    return 0;
}