
#include <iostream>
#include "Stack.h"
#include "cmath"

bool isOperator(char chr);
int precedence(char chr);
bool isOpenBracket(char chr);
bool isCloseBracket(char chr);
bool isBalancedBracket(std::string str);
std::string reverse(std::string str);
int calculate(int a, int b, char oper);

std::string toPrefix(std::string str);
std::string toPostfix(std::string str);
std::string postfixToPrefix(std::string str);
std::string prefixToPostfix(std::string str);
std::string prefixToInfix(std::string str);
std::string postfixToInfix(std::string str);
int postfixEvaluation(std::string str);
int prefixEvaluation(std::string str);

int main(int argc, char const *argv[])
{
    // std::string str = "A * (B + C / D)";
    std::string str = "2 ^ 3 * 2 + 5";
    // std::string str2 = "([[{A + B} *]] (C))";

    std::cout << toPostfix(str) << std::endl;
    std::cout << toPrefix(str) << std::endl;
    std::cout << postfixToPrefix(toPostfix(str)) << std::endl;
    std::cout << prefixToPostfix(toPrefix(str)) << std::endl;
    std::cout << prefixToInfix(toPrefix(str)) << std::endl;
    std::cout << postfixToInfix(toPostfix(str)) << std::endl;
    std::cout << postfixEvaluation(toPostfix(str)) << std::endl;
    std::cout << prefixEvaluation(toPrefix(str)) << std::endl;

    // if (isBalancedBracket(str2))
    // {
    //     std::cout << "true";
    // }
    // else
    // {
    //     std::cout << "Flase";
    // }

    // return 0;
}

std::string toPostfix(std::string str)
{
    Stack<char> operatorStack;
    std::string PSN = "";
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        if (isalnum(chr))
        {
            PSN += chr;
        }
        else if (isOpenBracket(chr))
        {
            operatorStack.push(chr);
        }
        else if (isCloseBracket(chr))
        {
            while (!isOpenBracket(operatorStack.peek()))
            {
                PSN += operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (isOperator(chr))
        {
            while (!operatorStack.isEmpty() && precedence(operatorStack.peek()) >= precedence(chr))
            {
                PSN += operatorStack.pop();
            }
            operatorStack.push(chr);
        }
    }

    while (!operatorStack.isEmpty())
    {
        PSN += operatorStack.pop();
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

bool isOpenBracket(char chr)
{
    return chr == '(' || chr == '{' || chr == '[';
}
bool isCloseBracket(char chr)
{
    return chr == ')' || chr == '}' || chr == ']';
}

bool isBalancedBracket(std::string str)
{
    Stack<char> bracketStack;
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        if (isOpenBracket(chr))
        {
            bracketStack.push(chr);
        }
        else if (isCloseBracket(chr))
        {
            if (bracketStack.isEmpty())
                return false;
            char chr2 = bracketStack.pop();
            if (chr == ')' && chr2 != '(')
                return false;
            if (chr == ']' && chr2 != '[')
                return false;
            if (chr == '}' && chr2 != '{')
                return false;
        }
    }

    return bracketStack.isEmpty();
}

std::string toPrefix(std::string str)
{
    str = reverse(str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }

    std::string prefix = toPostfix(str);

    return reverse(prefix);
}

std::string reverse(std::string str)
{
    std::string output = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        output += str[i];
    }
    return output;
}

std::string postfixToPrefix(std::string str)
{
    Stack<std::string> prefixStack;
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        if (isalnum(chr))
        {
            std::string temp = "";
            prefixStack.push(chr + temp);
        }
        else if (isOperator(chr))
        {
            std::string operand1 = prefixStack.pop();
            std::string operand2 = prefixStack.pop();

            prefixStack.push(chr + operand2 + operand1);
        }
    }

    std::string result = "";
    while (!prefixStack.isEmpty())
    {
        result += prefixStack.pop();
    }

    return result;
}
std::string prefixToPostfix(std::string str)
{
    Stack<std::string> postfixStack;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char chr = str[i];
        if (isalnum(chr))
        {
            std::string temp = "";
            postfixStack.push(chr + temp);
        }
        else if (isOperator(chr))
        {
            std::string operand1 = postfixStack.pop();
            std::string operand2 = postfixStack.pop();

            postfixStack.push(operand1 + operand2 + chr);
        }
    }

    std::string result = "";
    while (!postfixStack.isEmpty())
    {
        result += postfixStack.pop();
    }

    return result;

    // return reverse(postfixToPrefix(reverse(str)));
}

std::string prefixToInfix(std::string str)
{
    Stack<std::string> infixStack;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char chr = str[i];
        if (isalnum(chr))
        {
            std::string temp = "";
            infixStack.push(chr + temp);
        }
        else if (isOperator(chr))
        {
            std::string operand1 = infixStack.pop();
            std::string operand2 = infixStack.pop();

            infixStack.push(operand1 + chr + operand2);
        }
    }

    std::string result = "";
    while (!infixStack.isEmpty())
    {
        result += infixStack.pop();
    }

    return result;
}
std::string postfixToInfix(std::string str)
{
    Stack<std::string> infixStack;
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        if (isalnum(chr))
        {
            std::string temp = "";
            infixStack.push(chr + temp);
        }
        else if (isOperator(chr))
        {
            std::string operand1 = infixStack.pop();
            std::string operand2 = infixStack.pop();

            infixStack.push(operand2 + chr + operand1);
        }
    }

    std::string result = "";
    while (!infixStack.isEmpty())
    {
        result += infixStack.pop();
    }

    return result;
}

int postfixEvaluation(std::string str)
{
    Stack<int> stack;
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        if (isalnum(chr))
        {
            stack.push(chr - '0');
        }
        else if (isOperator(chr))
        {
            int operand1 = stack.pop();
            int operand2 = stack.pop();

            stack.push(calculate(operand2, operand1, chr));
        }
    }

    return stack.pop();
}
int prefixEvaluation(std::string str)
{
    Stack<int> stack;
    for (int i = str.length(); i >= 0; i--)
    {
        char chr = str[i];
        if (isalnum(chr))
        {
            stack.push(chr - '0');
        }
        else if (isOperator(chr))
        {
            int operand1 = stack.pop();
            int operand2 = stack.pop();

            stack.push(calculate(operand1, operand2, chr));
        }
    }

    return stack.pop();
}

int calculate(int a, int b, char oper)
{
    switch (oper)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '^':
        return pow(a, b);
        break;

    default:
        return 0;
        break;
    }
}