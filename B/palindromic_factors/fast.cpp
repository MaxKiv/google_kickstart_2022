#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

// print vector helper function
void printVec(std::vector<int> &vec) {
  for (const int &el : vec) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

// Factorize an integer
std::vector<int> separation(const int &int_in) {
  int integer = int_in;
  int oom = log10(integer);
  std::vector<int> factors(oom + 1);
  for (std::vector<int>::reverse_iterator rit = factors.rbegin();
       rit != factors.rend(); rit++) {
    (*rit) = integer % 10;
    integer /= 10;
  }
  return factors;
}

// Rebuild integer from factors
int integration(std::vector<int> &factors) {
  int out = 0;
  int oom = 1;
  for (std::vector<int>::reverse_iterator rit = factors.rbegin();
       rit != factors.rend(); rit++) {
    out += (*rit) * oom;
    oom *= 10;
  }
  return out;
}

std::vector<int> factorise(const int& integer) {
  int max = pow(10,10);
  std::vector<int> factors;
  for(size_t i = 2; i < max; i++) {
    if((integer % i) == 0) {
      factors.push_back(i);
    }
  }
  return factors;
}

// Std like pass iterators
bool isPalindrome(std::vector<int>::iterator& begin, std::vector<int>::iterator& end) {
  // base case: is dist(begin,end) < 1
  if(std::distance(begin,end) < 1) {
    return true;
  }
  // main loop: check if outer left = outer right
  if((*begin) != (*end)) {
    return false;
  } else {
    return isPalindrome(++begin,--end); 
  }
}
// my attempt at a faster palindrome, uses isPalindrome
bool fasterPalindrome(int integer, std::map<int, bool> &memo) {
  // integer is in memo map
  if (memo.find(integer) != memo.end()) {
    std::cout << "hit map with " << integer << std::endl;
    return memo[integer];
  }
  std::cout << "no map hit :(" << std::endl;
  // no cache hit, we have to do work: separation the integer
  std::vector<int> fac = separation(integer);
  // look at outer values, they must be equal if this int is to be a palindrome
  std::vector<int>::iterator begin = fac.begin();
  std::vector<int>::iterator end = (fac.end() -1 );
  return isPalindrome(begin, end);
}
// Test palindrome alg
void testPalindrome() {
  std::map<int,bool> memo;
  std::vector<int> PalindromeTest{1, 2, 11, 22, 121, 242, 100, 123, 234, 567}; 
  for (size_t t = 0; t < PalindromeTest.size(); t++) {
    std::cout << PalindromeTest[t] << " is a palindrome? "
              << fasterPalindrome(PalindromeTest[t], memo) << std::endl;
  }
}
// main solve loop
void solve(int A) {
  std::vector<int> fac = factorise(A);
  printVec(fac);
  std::map<int,bool> memo;
  for(auto it = fac.begin(); it != fac.end(); it++) {
    if(!fasterPalindrome((*it), memo)) {
      fac.erase(it--);
    }
  }
  printVec(fac);
  std::cout << fac.size() << std::endl;

}

int main() {
  int T;
  std::cin >> T;
  for (size_t t = 1; t <= T; t++) {
    int A;
    std::cin >> A;
    std::cout << "starting # " << t << " with int " << A;
    /* std::cout << "Case #" << t << ": "; */
    solve(A);
  }

  /* int t = 123456; */
  /* std::cout << t << std::endl; */
  /* std::vector<int> tfac = factorise(t); */
  /* printVec(tfac); */
  /* int tback = integration(tfac); */
  /* std::cout << "integration int = " << tback << std::endl; */

  /* testPalindrome(); */
  return 0;
}
