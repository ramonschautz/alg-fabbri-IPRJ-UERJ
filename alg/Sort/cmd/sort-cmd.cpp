#include <iostream>
#include <vector>
#include <iterator>
#include "sort.h"

int
main()
{
  std::vector<char> v(std::istream_iterator<char>(std::cin), {});
  if (!v.empty()) {
    sort_char(v.data(), v.size());
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, ""));
  }
  return 0;
}
