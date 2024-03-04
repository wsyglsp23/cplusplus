/*
  用于介绍explict的demo
  防止意想不到的一些隐式转换操作 如下图所示
*/

#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    //explicit
    Point(int x = 0, int y = 0)
        : x(x), y(y) {}
    Point operator=( const Point&p)
    {
      cout << "operator = " << endl;
    }
};

void displayPoint(const Point& p) 
{
    cout << "(" << p.x << "," 
         << p.y << ")" << endl;
}

int main()
{
    displayPoint(1);//传入的是int，结果发生了隐式转换
    Point p = 1;//在对象刚刚定义时, 即使你使用的是赋值操作符=, 也是会调用构造函数, 而不是重载的operator=运算符
    Point p2 = 1;//在对象刚刚定义时, 即使你使用的是赋值操作符=, 也是会调用构造函数, 而不是重载的operator=运算符
    p2 = p;//此时才是赋值重载
}