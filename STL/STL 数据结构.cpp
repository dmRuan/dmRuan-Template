/*队列*/
#include<queue>
queue<int> q;
q.front();//取出第一个元素
q.pop();//删除第一个元素
q.back();//取出最后一个元素
p.empty();//是否为空
p.push();//往后加元素

/*堆栈*/
#include<stack>
stack<int> s;
s.push();
s.pop();
s.empty();
s.top();


/*优先队列*/
#include<queue>
struct node
{
    bool operator < (struct node b) const
    {
        return value < b.value;//从大到小
        return value > b.value;//从小到大
    }
    int value, poin;
};
priority_queue<struct node>   pque;
pque.push();
pque.pop();
pque.empty();
pque.top();//默认返回一个最大的
