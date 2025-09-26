#include "sort.h"
#include <algorithm>

void
sort_char(char *v, int n)
{
  std::sort(v, v + n);
}
