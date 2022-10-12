#include <iostream>

template <typename T>
T pi_4(int n)
{
  double sum = 0;
  for(int i = 0; i < n; ++i)
  {
    switch(i%2)
    {
      case 0:
         sum += (T{1})/(2*i + 1);
         break;
      case 1:
        sum -= (T{1})/(2*i + 1);
        break;
    }
  }
  return sum;
}

int main()
{
  
  std::cout << 4*pi_4<double>(10000);
}