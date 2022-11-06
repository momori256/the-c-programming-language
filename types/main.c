#include <assert.h>

// f1 is function returning char.
char f1() { return 'a'; }

// f2 is function returning char.
char f2() { return 'b'; }

// a is array[] of pointer to function returning char.
char (*a[])() = {f1, f2};

// x is function returning pointer to
// array[] of pointer to function returning char.
char (*(*x())[])() { return &a; }

// int (*(*y[])())[];

// x is function returning pointer to
// array[] of pointer to function returning char.
// typedef char f_char_t();
// f_char_t *((*x())[]);
// char (*(*x())[])() { return &a; }

// x is array[13] of pointer to function returing int.
// typedef int (*fp_int_t)();
// fp_int_t z[13];

// typedef int arr_int_t[13];

// int (*f()[])();

int main() {
  // p is pointer to array[] of pointer to function returning char.
  char (*(*p)[])() = x();
  char r1 = (*p)[0]();
  assert(r1 == 'a');

  // fs is array[] of pointer to function returning char.
  char (**fs)() = *p;
  char r2 = fs[1]();
  assert(r2 == 'b');

  return 0;
}
