#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include<stdio.h>
int prime[100000],e;
const int L1D_CACHE_SIZE = 32768;
void segmented_sieve(int64_t limit, int segment_size = L1D_CACHE_SIZE)
{
  int sqrt = (int) std::sqrt((double) limit);
  int64_t count = (limit < 2) ? 0 : 1;
  int64_t s = 2;
  int64_t n = 3;
// vector used for sieving
  std::vector<char> sieve(segment_size);
// generate small primes <= sqrt
  std::vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;
std::vector<int> primes;
std::vector<int> next;
for (int64_t low = 0; low <= limit; low += segment_size)
  {
    std::fill(sieve.begin(), sieve.end(), 1);
// current segment = interval [low, high]
int64_t high = std::min(low + segment_size - 1, limit);
// store small primes needed to cross off multiples
    for (; s * s <= high; s++)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    // sieve the current segment
    for (std::size_t i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }
    prime[0]=2;e=1;
    for (; n <= high; n += 2)
      if (sieve[n - low]) // n is a prime
      {
          prime[e++]=n;
          //std::cout<<n<<" ";
          count++;
      }
}
//std::cout << count << " primes found." << std::endl;
}
int main(int argc, char** argv)
{
  // generate the primes below this number
  //freopen("output.txt","w",stdout);
  int64_t limit = 10000000;
  if (argc >= 2)
    limit = atol(argv[1]);
int size = L1D_CACHE_SIZE;
  if (argc >= 3)
    size = atoi(argv[2]);
segmented_sieve(limit, size);
//  for(int i=0;i<e;i++)
//    printf("%d ",prime[i]);
  return 0;
}
