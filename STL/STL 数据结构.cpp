/*����*/
#include<queue>
queue<int> q;
q.front();//ȡ����һ��Ԫ��
q.pop();//ɾ����һ��Ԫ��
q.back();//ȡ�����һ��Ԫ��
p.empty();//�Ƿ�Ϊ��
p.push();//�����Ԫ��

/*��ջ*/
#include<stack>
stack<int> s;
s.push();
s.pop();
s.empty();
s.top();


/*���ȶ���*/
#include<queue>
struct node
{
    bool operator < (struct node b) const
    {
        return value < b.value;//�Ӵ�С
        return value > b.value;//��С����
    }
    int value, poin;
};
priority_queue<struct node>   pque;
pque.push();
pque.pop();
pque.empty();
pque.top();//Ĭ�Ϸ���һ������
