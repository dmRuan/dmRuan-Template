/*�󼫽�
 *1.�����λ�ù�ϵ
 *2.͹���е���ϵ
 *3.�������Ͽɸ�ϸ��ȷ����������λ�ù�ϵ(8�����)
 */
double cross(Vector a, Vector b)//����a������b�߹��Ƕȵ�sinֵ
{
    return a.x*b.y - a.y*b.x;
}

/*�󶥵�����*/
//��֪�����ζԽǶ������꣬������������
void getSqu(Point a, Point &b, Point c, Point &d)
{
    b = Point((a.x+c.x-c.y+a.y)/2, (c.x-a.x+a.y+c.y)/2);
    d = Point((a.x+c.x+c.y-a.y)/2, (-c.x+a.x+a.y+c.y)/2);
}
//��֪�������������꣬���������
void getRec(Point a, Point b, Point c, Point &d)
{
    d = a+c-b;
}
