#include <bits/stdc++.h>

using namespace std;
bool balanced(string c){ 
  stack<char> a;
  char b;
  for (int n = 0; n < c.length(); n++){
    if (c[n] == '(' || c[n] == '[' || c[n] == '{'){
      a.push(c[n]);
      continue;
    }
    if (a.empty())
    return false;
    switch (c[n]) {
      case ')':
      b = a.top();
      a.pop();
      if (b == '{' || b == '[')
      return false;
      break;
      case '}':
      b = a.top();
      a.pop();
      if (b == '(' || b == '[')
      return false;
      break;
      case ']':
      b = a.top();
      a.pop();
      if (b == '(' || b == '{')
      return false;
      break;
    }
  }
  return (a.empty());
}
int main(){
  string c = "{{{}}}[[]]()[[]]{{{}}}";
  if (balanced(c))
  cout << "This is a balanced parantheses.";
  else
  cout << "This is not a balanced parantheses.";
  return 0;
}
