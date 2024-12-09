#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

std::map<char, int> precedence = 
{
    {'+', 2},
    {'-', 2},
    {'*', 3},
    {'/', 3},
    {'^', 4},
    {'(', 1}
};

std::string postfix(std::string infix)
{
    std::vector<char> stack;
    std::string output;

    for(char c : infix)
	{
        if(c >= 48 && c <= 57) output += c;
        else if (c == ')')
		{
            while(stack.back() != '(')
			{
                output += stack.back();
                stack.pop_back();
            }
            stack.pop_back();
            while(!stack.empty())
			{
                output += stack.back();
                stack.pop_back();
            }
        }
        else if(c == '(') stack.push_back(c);
        else{
            if(!stack.empty())
			{
                while(precedence[stack.back()] >= precedence[c])
				{
                    output += stack.back();
                    stack.pop_back();
                }
            }
            stack.push_back(c);
        }
    }
    while(!stack.empty())
	{
        output += stack.back();
        stack.pop_back();
    }

    return output;
}

int evaluate(std::string postfix)
{
    std::vector<char> stack;
    for(char sym : postfix)
	{
        if(sym >= 48 && sym <= 57) stack.push_back(sym);
        else
		{
            int b = stack.back() - '0';
            stack.pop_back();
            int a = stack.back() - '0';
            stack.pop_back();
            switch(sym)
			{
                case '+':
                stack.push_back('0' + a + b);
                break;

                case '-':
                stack.push_back('0' + a - b);
                break;

                case '/':
                stack.push_back('0' + a / b);
                break;

                case '*':
                stack.push_back('0' + a * b);
                break;

                case '^':
                stack.push_back('0' + floor(pow(a,b)));
                break;
            }
        }
    }

    return (stack.back() - '0');
}

int main()
{
    std::string infix = "3^2+5-6/3*5/(2+3)";
    std::cout << "Infix Expression: " << infix << "\n";
    std::cout << "Postfix: " << postfix(infix) << "\n";
    std::cout << "Eval: " << evaluate(postfix(infix)) << "\n";
}
