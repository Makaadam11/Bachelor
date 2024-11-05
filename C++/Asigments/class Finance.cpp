#include <iostream>
using namespace std;
class Finance
{
  public:
  static unsigned long long finance(unsigned long long n);
};

unsigned long long Finance::finance(unsigned long long n){

  unsigned long long result = 0;
  for(unsigned long long i = 0; i <= n ; i++){
    for(unsigned long long j = i; j <= n; j++){
      result += j;
      cout<< j;
    }
  }
  return result;
}
int main()
{
    Finance f1;
    cout << f1.finance(5);

    return 0;
}