// rfabbri 2025-09-25
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "../sort_char.h"

int
main()
{
  // Use C-style I/O for performance and to adhere to project style.
  char buffer[1000];
  size_t n = fread(buffer, sizeof(char), 1000, stdin);

  if (n == 0) {
    return 0;
  }

  // Sort the characters
  sort_char(buffer, n);

  // Print the sorted characters to stdout
  fwrite(buffer, sizeof(char), n, stdout);

  return 0;
}
