#include <functional>
#include <iostream>

template < typename T>
T product (std::function<T(T)> f,int j, const int n)
{
  return [j, n,f]() -> T 
  {T p = 1; 
    for(int i = j; i <= n; ++i){
      p *= f(i);
    }
    return p;
  }();
}

template < typename T>
T sum (std::function<T(int)> f,int j, const int n)
{
  return [j, n,f]() -> T 
  {T s = 0; 
    for(int i = j; i <= n; ++i){
      s += f(i);
    }
    return s;
  }();
}

template <typename T>
T pi_half (int number_terms)
{
  return 1 + sum<T>(
    [](int i)
    {
      return product<T>([](int j){return T(j)/(2*j +1);}, 1, i);
      //bad: still have stupid narrowing/cast/something... from  int to T 
    }
    ,1,number_terms);
}

int main()
{
  std::cout.precision(30);
  std::cout <<2*pi_half<double>(30);
}