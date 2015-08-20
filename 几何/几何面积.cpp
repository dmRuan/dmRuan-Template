/*三角形面积*/
//已知顶点坐标
double getArea(Point a, Point b, Point c)
{
    return 0.5*fabs(b.x*c.y + a.x*b.y + a.y*c.x
                    - b.x*a.y - c.x*b.y - a.x*c.y);
}
