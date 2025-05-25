
#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};

NODE *CreateNode(char x){
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
void push(stack &s, char x){
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
char& top(stack s) {
    return s.top->info;
}


//// INSERT CODE HERE
void Input_infix(char *infix, int &n){
    char k;
    cin >> k;
    n=0;
    while (k!='#'){
        infix[n++] = k;
        cin >> k;
    }
}

bool isOperator(char x){
    return ( (x=='-') || (x=='+')|| (x=='*') || (x=='/') || (x=='^') );
}
bool isBracket(char x){
    return ( (x=='(') || (x==')') );
}

int doUuTien(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/' || c == '%')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else 
        return -1;
}

void infix_to_postfix(char *ifx, int ni, char* pfx, int& np)
{
    np = 0;
    stack st;
    CreateEmptyStack(st);
    for(int i = 0; i < ni; i++)
    {
        if(ifx[i] == ' ')
            continue;
        if(!isOperator(ifx[i]) && !isBracket(ifx[i]))
            pfx[np++] = ifx[i];
        else if(isBracket(ifx[i]))
        {
            if(ifx[i] == '(')
                push(st, ifx[i]);
            else if(ifx[i] == ')')
            {
                while(top(st) != '(')
                {
                    pfx[np++] = top(st);
                    pop(st);
                }
                pop(st);
            }
        }
        else if(isOperator(ifx[i]))
        {
            while(!empty(st) && isOperator(top(st)) && doUuTien(ifx[i]) <= doUuTien(top(st)))
            {
                pfx[np++] = top(st);
                pop(st);
            }
            push(st, ifx[i]);
        }
    }
    while(!empty(st))
    {
        pfx[np++] = top(st);
        pop(st);
    }
}

void Output(char* pf, int np)
{
    for(int i = 0; i < np; i++)
    {
        cout << pf[i] << " ";
    }
}

////


int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
