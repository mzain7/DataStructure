#include <iostream>
#include "StackA.h"
#include <string>
// using namespace std;

bool validation(std::string str);
bool isOperator(char chr);
int precedence(char chr);
std::string postfix(std::string str);
int postfixEvaluation(std::string infix);
int calculate(int op1, int op2, char c);

int main(int argc, char const *argv[])
{
    std::string str = "(((1+2)*3)+6)/[2+3]}}}}";
    std::cout << validation(str);
    // std::string PSN = postfix(str);
    // std::cout << PSN;

    // std::cout << std::endl
    //           << postfixEvaluation(PSN);

    return 0;
}

bool validation(std::string str)
{
    Stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        char character = str[i];
        if (character == '(' || character == '[' || character == '{')
        {
            stack.push(character);
        }
        else if (character == ')')
        {
            if (stack.isEmpty() || stack.pop() != '(')
                return false;
        }
        else if (character == ']')
        {
            if (stack.isEmpty() || stack.pop() != '[')
                return false;
        }
        else if (character == '}')
        {
            if (stack.isEmpty() || stack.pop() != '{')
                return false;
        }
    }
    return stack.isEmpty();
}

std::string postfix(std::string str)
{
    Stack<char> operators(30);
    std::string PSN = "";

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

    return PSN;
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
    Stack<int> stack;
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

            stack.push(calculate(op1, op2, character));
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
    return 0;
}
