#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int main(int argc, char** argv) 
{
  if(argc != 3) return 0;
  std::vector<u_int8_t> v;
  std::fstream File(argv[1]);
  if(!File) return 0;
  std::string input;
  getline(File, input);

  for(long unsigned int i = 0; i < input.size(); i+=2) 
  {
    v.push_back(input[i]);
  }
  File.close();

  u_int16_t count[2];
  count[0] = 0;
  count[1] = 0;
  for(long unsigned int i = 0; i < v.size()-1; i++)
  {
    if(v[i] != v[i+1]) {
      count[(v[i]=='1'?1:0)]+=1;
    }
  }
  if(v[v.size()-1] != v[v.size()-2]) count[(v[v.size()-1]=='1'?1:0)]+=1;

  std::ofstream File2(argv[2]);
  if(!File2) return 0;
  File2 << count[1] << " " << count[0];
  File2.close();

  return 0;
}