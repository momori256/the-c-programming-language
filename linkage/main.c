#include <stdio.h>

extern int x;
extern void print();

void f(int x) {
  char* s = "hello";
  if (x) {
    s[0] = 'H';
  }
  printf("%s\n", s);
}

int main() {
  auto int i = 0;
  print();
  x += 10;
  print();

  f(0);
  f(1);
  f(0);
  return 0;
}
