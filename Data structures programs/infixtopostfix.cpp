#include<iostream>
using namespace std;
class stack
{char s[100];
 public:
 int top;
 stack()
 {top=-1;
 }
 void push(char u)
 {s[++top]=u;
  cout<<"pushed "<<u<<" in "<<top<<endl;
 }
 char pop()
 {cout<<"popped "<<s[top]<<" from "<<top<<endl;
  return s[top--];
 }
 char stacktop()
 {cout<<"stacktop "<<s[top]<<endl;
  return s[top];
 }
};
int priority(char x)
{if (x=='/' || x=='*')
    {return 2;
	}
 else if (x=='+' || x=='-')
    {return 1;
	}
 else if (x=='(')
    {return 0;
	}
 else 
    {return -1;
	}
}
void intopostfix(string s)
{stack stk;
 char x;
 string postfix;
 cout<<"slength"<<s.length()<<endl;
 for (int i=0;i<s.length();i++)
 {
  if (s[i]=='(')
  {stk.push(s[i]);
  }
  else if (s[i]==')')
  {x=stk.pop();
   while(stk.top!=-1 && x!='(')
   {postfix+=x;
    x=stk.pop();
   }  
  }
  else if (s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
  {char x;
   x=stk.stacktop();
   while (stk.top!=-1 && (priority(stk.stacktop())>=priority(s[i])))
   {
    x=stk.pop();
    postfix+=x;
   }
   stk.push(s[i]);
  }
  else
  {postfix+=s[i];
  }
 }
 while(stk.top!=-1)
	{
		char d;
		d=stk.pop();
		postfix+=d;
	}
 cout<<"\nPostfix length:"<<postfix.length();
 cout<<"\nPostfix:"<<postfix;
}
int main()
{string infix;
 cout<<"Enter the infix expression:";
 cin>>infix;
 intopostfix(infix);
}
