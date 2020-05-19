#include <iostream>
#include <string>
#include <vector>
#include <stack> 
using namespace std;
bool isValid(string s);

int main(){
    string s= "{[]}";
    cout<<isValid(s);
}

bool isValid(string s) {
    stack<char> stack; 
    int p_ctr = 0; // parenthesis
    int b_ctr = 0; // bracket
    int curly_ctr = 0; // curly braces

    for(unsigned long i=0;i<s.size();i++){
        switch (s[i])
        {
            case '(':
                stack.push('(');
                p_ctr++;
                break;
            case ')':
                p_ctr--;
                if(p_ctr < 0 || stack.top() != '(') return false;
                stack.pop();
                break;
            case '[':
                stack.push('[');
                b_ctr++;
                break;
            case ']':
                b_ctr--;
                if(b_ctr < 0|| stack.top() != '[') return false;
                stack.pop();
                break;
            case '{':
                stack.push('{');
                curly_ctr++;
                break;
            case '}':
                curly_ctr--;
                if(curly_ctr < 0|| stack.top() != '{') return false;
                stack.pop();
                break;
            default:
                break;
        }
    }
    if((p_ctr != 0) || (b_ctr != 0) || (curly_ctr != 0)) return false;
    else return true;
}