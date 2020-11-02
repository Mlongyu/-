#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {int mid=nFloors/2;
        vector<string> ans;
      string s[2*nFloors-1];
      for(int i=0;i<nFloors;i++){
        s[mid+i]=s[mid-i]='*';
        ans.push_back(s);
      }

      return ans;
    }
};