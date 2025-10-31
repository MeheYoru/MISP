#include <iostream>
#include <vector>
#include <stack>



int main(int argc, char** argv) 
{
  std::string s;
  std::cin >> s;
  std::stack<std::pair<u_int16_t, char>> stack;

  for(u_int16_t i = 0; i < s.size(); i++) {
      if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
        stack.push(std::make_pair(i+1, s[i]));
      }
      if((s[i] == ']'))
      {
        if(stack.top().second == '[') stack.pop();
        else
        {
          std::cout << i+1 << "\n";
          return 0;
        }
      }
      if((s[i] == '}'))
      {
        if(stack.top().second == '{') stack.pop();
        else
        {
          std::cout << i+1 << "\n";
          return 0;
        }
      }
      if((s[i] == ')'))
      {
        if(stack.top().second == '(') stack.pop();
        else
        {
          std::cout << i+1 << "\n";
          return 0;
        }
      }

      
  }
  if(stack.empty()) {
    std::cout << "SUCCESS" << std::endl;
    return 0;
  }
    auto it = stack.top();
  
  while(!stack.empty()) {
      it = stack.top();
      stack.pop();
  }
  std::cout << it.first << std::endl;
  return 0;

}