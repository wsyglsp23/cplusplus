#include <functional>
#include <iostream>
using namespace std;
void hello1()
{
    cout << "hello" << endl;
}
int main()
{
     function<void()> func1 = hello1;
     func1();
     return 0;
}