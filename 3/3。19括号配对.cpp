#include <iostream>
#include <stack>
#include <string>

bool areBracketsBalanced(const std::string &expression) {
    std::stack<char> bracketStack;  // 用于存放括号的栈

    for (char c : expression) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            bracketStack.push(c);  // 如果是左括号，入栈
        } 
        else if (c == ')' || c == ']' || c == '}')
        {
            if (bracketStack.empty())
            {
                return false; // 如果右括号多于左括号，表示不匹配，返回 false
            }

            char top = bracketStack.top();  // 取出栈顶元素
            bracketStack.pop();  //弹出栈顶元素

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) 
            {
                return false; // 如果括号不匹配，返回 false
            }
        }
    }

    return bracketStack.empty(); // 如果栈未空，证明还有未匹配的左括号，返回 false
}

int main() {
    std::string expression;
    std::cout << "Enter an expression PLZ: " << std::endl;
    std::cin >> expression;

    if (areBracketsBalanced(expression)) {
        std::cout << "Brackets are perfectly balanced!" << std::endl;
    } else {
        std::cout << "Brackets are NOT balanced!" << std::endl;
    }

    return 0;
}
