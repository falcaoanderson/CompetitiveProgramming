#include <iostream>
 
using namespace std;
 
int main ()
{
 
  int t;
  cin >> t;
 
  while (t--)
    {
      int h, m;
      cin >> h >> m;
      cout << 60 - m + 60 * (23 - h) << endl;
    }
 
  return 0;
}