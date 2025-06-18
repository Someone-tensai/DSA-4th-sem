//Infix to Postfix and evalutation of Postfix using Stack
#include<iostream>
#include<string>

using namespace std;
#define MAX_SIZE 100

int precedence(char);
string infix_to_postfix(string);
int evaluate_postfix(string);

template <typename T>
class stack {
public:

    int top = -1;
    T data[MAX_SIZE];

    void push(char x)
    {
        if(top >= MAX_SIZE - 1)
        {
            printf("Stack Full");
            return;
        }

        data[++top] = x;
    }
    T pop()
    {
        if(top == -1)
        {
            printf("Empty Stack");
            return T();
        }
       return data[top--];
    }
    T topp()
    {
        if(top == -1)
        {
            printf("Empty Stack");
            return T();
        }
        return data[top];
    }
    int is_empty()
    {
        if(top == -1)
        {
            return 1;
        }
        return 0;
    }
     void display()
    {
        cout << "\n";
    for(int i=0; i <= top; i++)
    {
        cout << data[i] << "\n";
    }
    }

};

int main()
{
    string str;

    printf("Enter a infix expression: ");
    cin >> str;

    string postfix = infix_to_postfix(str);
    //string prefix = infix_to_prefix(str);
    cout << "Postfix Expression: " << postfix;

    int ans = evaluate_postfix(postfix);
    cout << "\nEvaluated Postfix: " << ans;

}

int precedence(char a)
{
    if(a == '+' || a == '-') return 1;
    if(a == '*' || a == '/') return 2;
    return 0;
}

string infix_to_postfix(string inf)
{
    stack<char> stack_1;
    string post;
    for (char c: inf)
    {
        if(c >= '0' && c <= '9')
        {
            post += c;
        }
        else if(c == '(')
        {
            stack_1.push(c);
        }

        else if(c == ')')
        {
            
            while(!stack_1.is_empty() && stack_1.topp() != '(')
            {
                post += stack_1.topp();
                stack_1.pop();
            }
            stack_1.pop();
        }
        
        else if( c == '+' || c == '-' || c == '*' || c == '/' )
        {
            while(!stack_1.is_empty() && (precedence(c) <= precedence(stack_1.topp())))
            {
                post += stack_1.topp();
                stack_1.pop();
            }
            stack_1.push(c);
        }
    }
        while(!stack_1.is_empty()){
            post += stack_1.topp();
            stack_1.pop();
        }
    return post;
}

int evaluate_postfix(string post)
{
    stack<int> stack_1;
    for(char c: post)
    {
        if(c >= '0' && c <= '9')
        {
            stack_1.push(c - '0');
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' )
        {
            int val2 = stack_1.pop();
            int val1 = stack_1.pop();
            switch(c){

                case '+': stack_1.push(val1 + val2); break;
                case '-': stack_1.push(val1 - val2); break;
                case '*': stack_1.push(val1 * val2); break;
                case '/': stack_1.push(val1 / val2); break;
            }
        }

    }
    return stack_1.topp();
}