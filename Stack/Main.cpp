#include <iostream>
#include "StackLL.h"

int main(int argc, char const *argv[])
{
    StackLL<int> stack(20);
    // std::cout << stack.size;

    stack.push(70);
    stack.push(80);
    stack.push(60);
    stack.push(40);
    stack.push(20);
    stack.push(10);
    stack.push(0);
    stack.push(30);
    stack.push(40);
    std::cout <<    stack.display()<<std::endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    std::cout <<    stack.display();
    std::cout << "ENDED!";



    return 0;
}
