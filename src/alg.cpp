#include "tstack.h"
#include <string>
#include <iostream>
using namespace std;

int prioritet(char ch)
{
    switch (ch)
    {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    default: return -1;
    }
}
string infx2pstfx(string pstfx)
{
    TStack<char> stack;
    string vivod = "";
    for (int i = 0; i < pstfx.size(); i++)
    {
        char ch = pstfx[i];
        int priority = prioritet(ch);

        if (priority == -1)
              vivod.append(string(1,ch));
        else
            if (stack.isEmpty() || priority == 0 || priority > prioritet(stack.get()))
                stack.push(ch);
            else
            {
                if (ch == ')')
                while (true)
                {
                    char lastStackEl = stack.get();
                    stack.pop();
                    if (lastStackEl != '(')
                    vivod.append(string(1,lastStackEl));
                    else
                        break;
                }
            else
            {
                while (!stack.isEmpty())
                {
                    char lastStackEl = stack.get();
                    stack.pop();
                    if (prioritet(lastStackEl) >= priority)
                    vivod.append(string(1,lastStackEl));
                }
                stack.push(ch);
            }
           }
    }

        while (!stack.isEmpty()) {
        char lastStackEl = stack.get();
        stack.pop();
        vivod.append(string(1,lastStackEl));
        }
    return vivod;  
}
int vichislen(int a, int b, char search)
{
    switch (search)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return -1;
    }
}
int eval(string pst)
{
    TStack<int> stack;
    for (int i = 0; i < pst.size(); i++)
    {
        char ch = pst[i];
        int priority = prioritet(ch);

        if (priority == -1)
            stack.push(ch - 48);
        else
        {
            int  a = stack.get();
            stack.pop();

            int b = stack.get();
            stack.pop();

            int result = vichislen(a, b, ch);
            stack.push(result);
        }

    }
    return stack.get();
}
