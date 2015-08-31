/*点的结构体*/
struct Point {
    double x, y;
    Point() {}
    void input() {
        scanf("%lf %lf", &x, &y);
    }
    Point(double _x, double _y) {
        x = _x; y = _y;
    }
    Point operator +(const Point &b) const {
        return Point(x+b.x, y+b.y);
    }
    Point operator -(const Point &b) const {
        return Point(x-b.x, y-b.y);
    }
    //cross
    double operator ^(const Point &b) const {
        return x*b.y - y*b.x;
    }
    //dot
    double operator *(const Point &b) const {
        return x*b.x + y*b.y;
    }
    //after rotating around the origin B(radian), x and y value
    void transXY(double B) {
        double tx = x, ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) - ty*cos(B);
    }
};
/*线的结构体*/
struct Line {
    Point u, v;
    double k;
    Line() {}
    void input() {
        u.input(); v.input();
    }
    Line(Point _u, Point _v) {
        u = _u; v = _v;
    }
    double getk() {
        return atan2(v.y-u.y, v.x-v.x);
    }
    //is line intersection?
    //0 is coincide, 1 is parallel, 2 is intersection
    pair<int,Point> operator &(const Line &b) const
    {
        Point res = u;
        if( sgn((u-v)^(b.u-b.v)) == 0 )
        {
            if( sgn((u-b.v)^(b.u-b.v)) == 0 )
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行
        }
        double t = ((u-b.u)^(b.u-b.v))/((u-v)^(b.u-b.v));
        res.x += (v.x-u.x)*t;
        res.y += (v.y-u.y)*t;
        return make_pair(2,res);
    }
};

/*sign*/
int sgn(double x) {
    return (x>eps) - (x<-eps);
}
double cross(Point a, Point b, Point o) {
    return (a-o) ^ (b-o);
}
double dist(Point a, Point b) {
    return sqrt((a-b) * (a-b));
}
/*is segment intersection?*/
bool isInter(Point a, Point b, Point c, Point d) {
    return
        max(a.x,b.x) >= min(c.x,d.x) &&
        max(a.y,b.y) >= min(c.y,d.y) &&
        max(c.x,d.x) >= min(a.x,b.x) &&
        max(c.y,d.y) >= min(a.y,b.y) &&
        sgn(cross(c,b,a) * cross(d,b,a)) <= 0 &&
        sgn(cross(a,d,c) * cross(b,d,c)) <= 0;
}

