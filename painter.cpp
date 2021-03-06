//
// Created by jarozin on 25.04.22.
//

#include "painter.h"
QPointF convert_point(point &a)
{
    return QPointF(a.x + 300, a.y + 300);
}
int draw_cube(cube &my_cube, QPainter &qp)
{
    draw_point_data(my_cube.points, qp);
    draw_links_data(my_cube.points, my_cube.links, qp);
    return NONE;
}
int draw_point(point &a, QPainter &qp)
{
    qp.drawPoint(convert_point(a));
    return NONE;
}
int draw_point_data(point_data &a, QPainter &qp)
{
    for (int i = 0; i < a.n; i++)
    {
        draw_point(a.arr[i], qp);
    }
    return NONE;
}
int draw_links_data(point_data &points, links_data &links, QPainter &qp)
{
    QPointF p1;
    QPointF p2;
    link num;
    for (int i = 0; i < links.n; i++)
    {
        num = links.arr[i];
        p1 = convert_point(points.arr[num.p1]);
        p2 = convert_point(points.arr[num.p2]);
        qp.drawLine(p1, p2);
    }
    return NONE;
}