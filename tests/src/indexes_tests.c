// Copyright 06-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "indexes_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void indexes_tests (void) {
  puts("'indexes' tests:");

  int ix;
  char *s;

  Tx *tx = tx_sub(tx_new("xxxabc"), 3, 3);
  tx_indexes(&ix, &s, tx, (char *[]){NULL});
  assert(ix == -1);
  assert(*s == 0);
  tx_indexes(&ix, &s, tx, (char *[]){"b", NULL});
  assert(ix == -1);
  assert(*s == 0);
  tx_indexes(&ix, &s, tx, (char *[]){"b", "a", "c", NULL});
  assert(ix == -1);
  assert(*s == 0);

  tx = tx_sub(tx_new("xxxabc"), 3, 4);
  tx_indexes(&ix, &s, tx, (char *[]){NULL});
  assert(ix == -1);
  assert(*s == 0);
  tx_indexes(&ix, &s, tx, (char *[]){"b", NULL});
  assert(ix == -1);
  assert(*s == 0);
  tx_indexes(&ix, &s, tx, (char *[]){"b", "a", "c", NULL});
  assert(ix == 0);
  assert(s[0] == 'a' && s[1] == 0);

  tx = tx_sub(tx_new("xxxabc"), 3, 6);
  tx_indexes(&ix, &s, tx, (char *[]){NULL});
  assert(ix == -1);
  assert(*s == 0);
  tx_indexes(&ix, &s, tx, (char *[]){"b", NULL});
  assert(ix == 1);
  assert(s[0] == 'b' && s[1] == 0);
  tx_indexes(&ix, &s, tx, (char *[]){"b", "a", "c", NULL});
  assert(ix == 0);
  assert(s[0] == 'a' && s[1] == 0);
  tx_indexes(&ix, &s, tx, (char *[]){"b", "ab", "c", NULL});
  assert(ix == 0);
  assert(s[0] == 'a' && s[1] == 'b' && s[2] == 0);
  tx_indexes(&ix, &s, tx, (char *[]){"c", "b", "abc", NULL});
  assert(ix == 0);
  assert(s[0] == 'a' && s[1] == 'b' && s[2] == 'c' && s[3] == 0);

  puts("    Finished");
}
