#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

#define MAX(a, b) (a) >= (b) ? (a) : (b)

#define TXT_SIZE (1024)
#define HIS_SIZE (26)

int main() {
  char text[TXT_SIZE] = {'\0'};
  (void)fread(text, TXT_SIZE, sizeof(char), stdin);
  const size_t sz = strlen(text);

  int hist[HIS_SIZE] = {0};
  rep(i, sz) {
    const char c = text[i];
    if (!isalnum(c)) {
      continue;
    }
    ++hist[tolower(c) - 'a'];
  }

  rep(i, HIS_SIZE) { printf("%c%c", i + 'a', i == HIS_SIZE - 1 ? '\n' : ' '); }
  rep(i, HIS_SIZE) { printf("-%c", i == HIS_SIZE - 1 ? '\n' : '-'); }

  int mx = 0;
  rep(i, HIS_SIZE) { mx = MAX(mx, hist[i]); }

  rep(i, mx) {
    rep(j, HIS_SIZE) {
      printf("%c%c", hist[j] > i ? '*' : ' ', j == HIS_SIZE - 1 ? '\n' : ' ');
    }
  }

  return 0;
}
