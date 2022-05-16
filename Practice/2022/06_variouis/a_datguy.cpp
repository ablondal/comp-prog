#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long get_long(long long n)
{
  unsigned long long number_of_digits = 0;

  do {
    ++number_of_digits;
    n /= 10;
  } while (n);
  return number_of_digits;
}

long long find_digit(long long n, long long find)
{
  long long index = get_long(n);
  while ((index - 1) != find)
  {
    n /= 10;
    --index;
  }
  return n % 10;
}
int main()
{
  long long n, temp, current_len;
  cin >> n;

  vector<long long> vect;

  for (long long i = 0; i < n; ++i)
  {
    cin >> temp;
    vect.push_back(temp);
  }

  for (long long i = 0; i < vect.size(); ++i)
  {
    //Getting length of each number
    current_len = get_long(vect[i]);
    long long index = current_len - 1;
    bool check_front = true, check_back = true;
    if (i == 0)
    {
      check_front = false;
    }
    else if (i == vect.size() - 1)
    {
      check_back = false;
    }
    while (index >= 0) 
    {
      for (long long j = find_digit(vect[i],index),p = 0-j; j + p < 10; p++)
      {
        temp = vect[i];
        temp += p * pow(10, (current_len - index - 1));

        if (check_back)
        {
          if (temp > vect[i + 1])
          {
            if (index == 0 && find_digit(vect[i], index) + p == 0)
            {
              continue;
            }
            vect[i] = temp;
            for (long long k = 0; k < vect.size(); k++)
            {
              cout << vect[k] << " ";
            }
            return 0;
          }
        }
        if (check_front)
        {
          if (temp < vect[i - 1])
          {
            if (index == 0 && find_digit(vect[i], index) + p == 0)
            {
              continue;
            }
            vect[i] = temp;
            long long k = 0;
            while(k<vect.size()-1)
            {
              cout << vect[k] << " ";
              k++;
            }
            cout << vect[k];
            return 0;
          }
        }
      }
      --index;
    }
  }
  cout << "impossible";
  return 0;
}