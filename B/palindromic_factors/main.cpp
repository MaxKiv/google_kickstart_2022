#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void printVec(std::vector<int> &vec) {
  for (const int &el : vec) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

std::vector<int> factorize(int &integer) {
  std::vector<int> factors;

  for (int f = 1; f <= integer; f++) {
    if ((integer % f) == 0) {
      factors.push_back(f);
    }
  }
  return factors;
}

std::map<int, bool> palindromeMemoMap;
bool isPalindrome(int integer) {
    int integerCopy(integer);
  /* std::cout << "map contains:" << std::endl; */
  /* for (const auto &[key, value] : palindromeMemoMap) { */
  /*   std::cout << "[" << key << "]" << value << "; "; */
  /* } */
  // check its memoised
  if (palindromeMemoMap.find(integer) != palindromeMemoMap.end()) {
    /* std::cout << "found in map" << std::endl; */
    return palindromeMemoMap[integer];
  }
  // get integer elements
  std::vector<int> int_elements;
  while (integer > 0) {
    int_elements.push_back(integer % 10);
    integer /= 10;
  }
  int j = int_elements.size() - 1;
  for (size_t i = 0; i < int_elements.size(); i++) {
    /* std::cout << "i: " << i << " j: " << j << std::endl; */
    if (i >= j) {
      /* std::cout << "i >= (j-1)" << std::endl; */
      palindromeMemoMap.insert(std::pair<int, bool>(integerCopy, true));
      return true;
    }
    if (int_elements[i] != int_elements[j]) {
      /* std::cout << "int_el[i]: " << int_elements[i] << " != int_el[j]: " <<
       * int_elements[j] */
      /* << std::endl; */
      palindromeMemoMap.insert(std::pair<int, bool>(integerCopy, false));
      return false;
    }
    j--;
  }
  palindromeMemoMap.insert(std::pair<int, bool>(integerCopy, true));
  return true;
}
void testPalindrome() {
  std::vector<int> PalindromeTest{1, 2, 11, 22, 121, 242, 100, 123, 234, 567};
  for (size_t t = 0; t < PalindromeTest.size(); t++) {
    /* std::cout << PalindromeTest[t] << " is a palindrome? " */
    /*           << isPalindrome(PalindromeTest[t]) << std::endl; */
  }
}
void solve(int A) {
  auto fac = factorize(A);
  auto endOfPalinDromesIt = std::remove_if(
      fac.begin(), fac.end(), std::not1(std::ptr_fun<int>(isPalindrome)));
  fac.erase(endOfPalinDromesIt, fac.end());
  /* printVec(fac); */
  std::cout << fac.size() << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  for (size_t t = 1; t <= T; t++) {
    int A;
    std::cin >> A;
    std::cout << "Case #" << t << ": ";
    solve(A);
  }
  return 0;
}
