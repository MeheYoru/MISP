#include <bits/stdc++.h>
#define INT u_int16_t

int main(int argc, char** argv)
{
  if(argc!=3) return 0;

  std::fstream File(argv[1]);
  if(!File) return 0;
  INT N;
  File >> N;
  std::vector<INT> v;

  for(INT i=0; i < N; i++) 
  {
    INT temp;
    File >> temp;
    v.push_back(temp);
  }
  File.close();
  std::sort(v.begin(), v.end()); 
  INT first = 0, second = 0;
  for(INT i = 0; i < v.size()/2; i++)
  {
    first += v[i];
    second += v[v.size()/2+i];
  }

  std::fstream File2(argv[2]);
  if(!File2) return 0;
  File2 << std::max(first, second) - std::min(first, second);
  return 0;

}