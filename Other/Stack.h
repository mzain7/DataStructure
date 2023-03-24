// #include <iostream>
// class Stack
// {
// private:
//     int top = -1;
//     char stack[20];


// public:
//     Stack()
//     {
//     }
//     void push(char val)
//     {
//         if (isFull())
//         {
//             std::cout << "Stack is full";
//             exit(1);
//         }
//         else
//         {
//             stack[++top] = val;
//         }
//     }

//     char pop()
//     {
//         if (isEmpty())
//         {
//             std::cout << "Stack is Empty";
//             return 0;
//         }
//         else
//         {
//             char temp = stack[top];
//             stack[top--] = '0';
//             return temp;
//         }
//     }

//     char peek()
//     {
//         if (isEmpty())
//         {
//             std::cout << "Stack is Empty";
//             return 0;
//         }
//         else
//         {
//             return stack[top];
//         }
//     }

//     int size()
//     {
//         return top;
//     }

//     bool isFull()
//     {
//         return top == sizeof(stack) / sizeof(char);
//     }

//     bool isEmpty()
//     {
//         return top < 0;
//     }

    
// };


// #pragma once

#include <iostream>

// using namespace std;

template <class T>
class Stack
{
	private:
		int size;
		int top;
		T *array;

	public:
		Stack(int size)
		{
			this->size = size;
			this->top = -1;
			this->array = new int[size];
		}

		~Stack()
		{
			delete[] array;
		}

		void push(T value)
		{
			if (isFull())
			{
				throw runtime_error("Stack Overflows! 😤");
			}
			array[++top] = value;
		}

		T pop()
		{
			if (isEmpty())
			{
				throw runtime_error("Stack is Empty! 😴");
			}
			return array[top--];
		}

		T peek()
		{
			if (isEmpty())
			{
				throw runtime_error("Stack is Empty! 😴");
			}
			return array[top];
		}

		bool isEmpty() const
		{
			return top == -1;
		}

		bool isFull()
		{
			return top + 1 == size;
		}

		std::string display()
		{
			if (isEmpty())
			{
				return "Currently Empty";
			}
			string result = "";
			for (int i = 0; i < top + 1; i++)
			{
				result += to_string(array[i]) + " ";
			}
			return result;
		}

		friend std::ostream &operator<<(std::ostream &os, const Stack<T> &s)
		{
			if (s.isEmpty())
				return os << "Stack: Currently Empty" << endl;
			os << "Stack: ";
			for (int i = 0; i < s.top + 1; i++)
			{
				os << s.array[i] << " ";
			}
			os << endl;
			return os;
		}
};