/*求极角
 *1.求点线位置关系
 *2.凸包中点间关系
 *3.与点积相结合可更细致确定两向量的位置关系(8种情况)
 */
double cross(Vector a, Vector b)//向量a到向量b走过角度的sin值
{
    return a.x*b.y - a.y*b.x;
}

/*求顶点坐标*/
//已知正方形对角顶点坐标，求正方形坐标
void getSqu(Point a, Point &b, Point c, Point &d)
{
    b = Point((a.x+c.x-c.y+a.y)/2, (c.x-a.x+a.y+c.y)/2);
    d = Point((a.x+c.x+c.y-a.y)/2, (-c.x+a.x+a.y+c.y)/2);
}
//已知矩形三顶点坐标，求矩形坐标
void getRec(Point a, Point b, Point c, Point &d)
{
    d = a+c-b;
}
