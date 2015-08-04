/*求极角
 *1.求点线位置关系
 *2.凸包中点间关系
 *3.与点积相结合可更细致确定两向量的位置关系(8种情况)
 */
double cross(Vector a, Vector b)//向量a到向量b走过角度的sin值
{
    return a.x*b.y - a.y*b.x;
}
