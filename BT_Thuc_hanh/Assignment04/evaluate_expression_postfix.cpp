
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE{
    float info;
    NODE *pNext;
};

NODE *CreateNode(float x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}
struct stack{
    NODE *top;
};
bool empty(const stack &s){
    return (s.top==NULL);
}
void CreateEmptyStack(stack &s){
    s.top=NULL;
}
void push(stack &s, float x){
    NODE *p=CreateNode(x);
    if(s.top==NULL) s.top= p;
    else {
        p->pNext=s.top;
        s.top=p;
    }
}
void pop (stack &s) {
    if(s.top==NULL) return;
    NODE *p= s.top;
    s.top=s.top->pNext;
    delete p;
}
float& top(stack s) {
    return s.top->info;
}
bool isOperator(char x){
    return ( (x=='-') || (x=='+')|| (x=='*') || (x=='/') || (x=='^') );
}
bool isBracket(char x){
    return ( (x=='(') || (x==')') );
}
void InputPostFix(char postix[], int &n){
    char k;
    cin >> k;
    n=0;
    while (k!='#'){
        postix[n++] = k;
        cin >> k;
    }
}

/// INSERT CODE HERE
float evaluate_expression(char* pf, int n)
{
    stack ans;
    for(int i = 0; i < n; i++)
    {
        if(!isOperator(pf[i]))
        {
            push(ans, (float)(pf[i] - '0'));
        }
        else
        {
            float temp1 = top(ans);
            pop(ans);
            float temp2 = top(ans);
            pop(ans);
            float temp = 0;
            if(pf[i] == '+')
            {
                temp = temp2 + temp1;
            }
            else if(pf[i] == '-')
            {
                temp = temp2 - temp1;
            }
            else if(pf[i] == '*')
            {
                temp = temp2 * temp1;
            }
            else if(pf[i] == '/')
            {
                temp = temp2 / temp1;
            }
            else if(pf[i] == '^')
            {
                temp = pow(temp2, temp1);
            }
            push(ans, temp);
        }
    }
    return top(ans);
}

///


int main() {
    char postfix[MAXN];
    int np;

    InputPostFix(postfix, np);
    // Output(postfix, np);

    cout.precision(3);
    cout << evaluate_expression(postfix, np);

    return 0;
}
