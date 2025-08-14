# About

# Programming Language
- All projects we ask in this folder are in C/C++

## C Coding Style
- Follow K&R style closely, the one in Ansi C programming language
- Keep it ANSI-C: Avoid more recent C-constructs unless necessary or clearly
  better, in which case you shuld point out a more recent feature is being used
- Do not use arrays with a variable number of elements. Use the classic malloc
  if the number of elements is variable
- C++ files will be named .h, .cpp, .hpp
- Beyond K&R and above, GNU C style guide from FSF and coding conventions from Google software engineers, For instance:
    - function names start at column 1 of the file
    - The function type goes on the line above the function name
- Lastly, you may fall back to conventions from VXL (formely Target/TargetJr),
  such as folder structure
- use short variable names unless the code is big and professional-grade, in which case
  you fallback to long descriptive variable names
- floating point: use float by default for brevity but suggest double if the code is highly numeric
  when appropriate
- Spacing between symbols in for and while, print, etc like i = 3 + 4, not i=3+4.
- Minimize blank lines while keeping code legible
- Do not change one-liners in my code if I do not want to. 
- Do oot repeat couts
- Make use of block comments /* */ where appropriate, not // all the time for multiline
- For commenting large blocks of code use #if 0 .. #endif if /* */ is already in
  the block

### Documentation
- The documentation should be in Latex in a doc/ subfolder
- It should include my name, email 
- It should also be in the CMake subfolder chain

## C Coding Technique
- Use the fastest, most efficient solution known
- Use the best algorith with the best asymptoptic complexity and best constants
  known for the problem and problem size in question
- Avoid low-level optimizations such as in-line assembly or unecessary
  adornments and compiler extensions, but do suggest them if you think they will
  be very useful
- C++, templates and STL-specific code may be used only sparringly
    - When using anything like classes, just use struct and stay as close as
      possible to C in terms of efficiency
- if a quantity is unsigned, use 'unsigned' instead of 'int'


## Tooling
- Use Cmake with Make

### Testing
- Use TDD (test-driven development) and specific code paths you have for it
    - In particular I expect to just write make test and code runs with test
      cases
- Use a general testing library that is actually used in production code across
  companies. Perhaps google code. Prioritize CTest if it comes with CMake.
- Tests should be inside a subfolder tests/ 
- When I type make, I expect the current folder and subfolders to make
- When I type make only in the tests, I expect it to build only the tests

## Debuggers
- DDD (gdb backend)
- Always compile C code with ample debug flags by default, -ggdb3 beyod just -g.
  You can hardcode that in CMakeLists.txt

## Initial setup
When I ask you "do the initial setup"  or similar, do:
- Verify that core dumps are droppable/enabled to drop in the current folder

# See Also / Further context
-The upper foler might give more context
