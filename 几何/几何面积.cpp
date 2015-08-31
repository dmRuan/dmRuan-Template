/*三角形面积*/
//已知顶点坐标
double getTriAre(Point a, Point b, Point o) {
    return fabs((a-o)^(b-o)) / 2.0;
}

double getPolAre(vector<Point> pol) {
    double ret = 0.0;
    int num = pol.size();
    for(int i = 0; i < num; i++) {
        ret += cross(pol[i], pol[(i+1)%num], Point(0,0));
    }
    return ret / 2.0;
}
