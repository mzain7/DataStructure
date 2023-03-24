#include <iostream>
#include "Stack.h"
#include <string>
// using namespace std;

bool isOperator(char chr);
int precedence(char chr);
int postfixEvaluation(std::string infix);
int calculate(int op1, int op2, char c);


class Stack1
{
private:
    int top = -1;
    int stack[20];

public:
    Stack1()
    {
    }
    void push(int val)
    {
        if (isFull())
        {
            std::cout << "Stack is full";
            exit(1);
        }
        else
        {
            stack[++top] = val;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is Empty";
            return 0;
        }
        else
        {
            int temp = stack[top];
            stack[top--] = 0;
            return temp;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is Empty";
            return 0;
        }
        else
        {
            return stack[top];
        }
    }

    int size()
    {
        return top;
    }

    bool isFull()
    {
        return top == sizeof(stack) / sizeof(char);
    }

    bool isEmpty()
    {
        return top < 0;
    }
};
int main(int argc, char const *argv[])
{
    Stack operators;
    std::string PSN = "";

    std::string str = "(((1+2)*3)+6)/(2+3)";

    for (int i = 0; i < str.length(); i++)
    {
        char character = str[i];

        if (isalnum(character))
        {
            PSN += character;
        }

        else if (character == '(')
        {
            operators.push(character);
        }
        else if (character == ')')
        {
            while (operators.peek() != '(')
            {
                PSN += operators.pop();
            }
            operators.pop();
        }
        else if (isOperator(character))
        {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(character))
            {
                PSN += operators.pop();
            }

            operators.push(character);
        }
    }

    while (!operators.isEmpty())
    {
        PSN += operators.pop();
    }

    std::cout << PSN;

    std::cout <<std::endl<< postfixEvaluation(PSN);

    return 0;
}
bool isOperator(char chr)
{
    return chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '^';
}

int precedence(char chr)
{
    switch (chr)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;

    default:
        return 0;
    }
}

int postfixEvaluation(std::string infix)
{
    Stack1 stack;
    for (int i = 0; i < infix.length(); i++)
    {
        char character = infix[i];

        if (isdigit(character))
        {
            stack.push(character - '0');
        }
        else if (isOperator(character))
        {
            int op1 = stack.pop();
            int op2 = stack.pop();

            stack.push(calculate(op1,op2,character));
            
        }
    }

    return stack.pop();



    
}

int calculate(int op1, int op2, char c)
    {
        switch (c)
        {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op2 / op1;
        default:
            return 0;
        }
    }
