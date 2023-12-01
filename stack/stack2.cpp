#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Stack
{
    T *elements;

public:
    size_t size = 0;
    size_t max = 0;
    // size_t top = -1;
    Stack(size_t size)
    {
        elements = (T *)(calloc(size, sizeof(T)));
        max = size;
    }
    T top()
    {
        if (size > 0)
        {
            return elements[size - 1];
        }
        throw out_of_range("Nothing on top");
    }
    T pop()
    {
        if (size == 0)
        {
            throw out_of_range("Nothing to pop");
        }
        T ret = elements[size - 1];
        size--;
        return ret;
    }
    T &operator[](size_t index)
    {
        if (index > size - 1)
        {

            throw out_of_range("Index out of range");
        }
        return elements[index];
    }
    void push(T value)
    {
        if (size + 1 <= max)
        {
            elements[size] = value;
            size++;
        }
        else
        {
            throw out_of_range("Stack is full");
        }
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '(' || c == ')');
}
bool isOperator(string s)
{
    if (s.size() > 1)
    {
        return false;
    }
    return isOperator(s[0]);
}
int precedence(char c)
{
    if (isOperator(c))
    {
        if (c == '+' || c == '-')
        {
            return 0;
        }
        if (c == '*' || c == '/')
        {
            return 1;
        }
        if (c == '$')
        {
            return 2;
        }
        return 3;
    }
    return -1;
}
string infixToPostfix(string input)
{
    Stack<char> stack(input.size());
    string postfix;
    for (size_t i = 0; i < input.size(); i++)
    {
        char currentChar = input[i];
        if (!isOperator(currentChar))
        {
            postfix.push_back(currentChar);
        }
        else
        {
            if (stack.size == 0)
            {
                stack.push(currentChar);
            }
            else
            {
                // if tos is greater or equal to currentchar push tos to postfix
                if (currentChar == ')')
                {
                    while (stack.top() != '(')
                    {
                        postfix.push_back(stack.pop());
                    }
                    stack.pop();
                }
                else
                {

                    if (stack.top() != '(' && precedence(stack.top()) >= precedence(currentChar))
                    {
                        do
                        {
                            char op = stack.pop();
                            if (op != '(' && op != ')')
                            {
                                postfix.push_back(op);
                            }
                        } while (stack.size > 0 && stack.top() != '(' && precedence(stack.top()) >= precedence(currentChar));
                        stack.push(currentChar);
                    }
                    else
                    {
                        stack.push(currentChar);
                    }
                }
            }
        }
    }
    while (stack.size > 0)
    {
        postfix.push_back(stack.pop());
    }
    return postfix;
}
int stringToInt(string s)
{
    int ret = 0;
    if (s[0] != '-')
    {

        for (size_t i = 0; i < s.size(); i++)
        {
            ret = ret * 10 + (s[i] - 48);
        }
        return ret;
    }
    else
    {
        for (size_t i = 1; i < s.size(); i++)
        {
            ret = ret * 10 + (s[i] - 48);
        }
        return -ret;
    }
}
int postfixResolve(string input)
{
    Stack<string> inputStack(input.size());
    for (size_t i = 0; i < input.size(); i++)
    {
        inputStack.push(string(1, input[i]));
    }
    int ret = 0;
    while (inputStack.size != 1)
    {
        for (size_t i = 2; i <= inputStack.size; i++)
        {
            if (isOperator(inputStack[i]))
            {
                int a = stringToInt(inputStack[i - 2]);
                int b = stringToInt(inputStack[i - 1]);
                int ans = 0;
                // is definetely an char;
                int op = inputStack[i][0];
                switch (op)
                {
                case '+':
                    ans = a + b;
                    break;
                case '-':
                    ans = a - b;
                    break;
                case '*':
                    ans = a * b;
                    break;
                case '/':
                    ans = a / b;
                    break;
                case '$':
                    ans = pow(a, b);
                    break;
                default:
                    break;
                }
                ret = ans;
                inputStack[i - 2] = to_string(ret);
                for (size_t j = i - 1; j < inputStack.size - 2; j++)
                {
                    inputStack[j] = inputStack[j + 2];
                }
                inputStack.pop();
                inputStack.pop();
                break;
            }
        }
    }
    return stringToInt(inputStack.top());
}
int main()
{
    string input;
    cout << "Enter valid expression" << endl;
    cin >> input;
    cout << infixToPostfix(input) << endl;
    cout << "Enter valid postfix expression" << endl;
    cin >> input;
    cout << postfixResolve(input) << endl;
    return 0;
}
