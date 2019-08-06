// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "to_tests.h"
#include "left_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void to_tests (void) {
  puts("'to' tests:");

  char *s = tx_to(tx_new(""));
  assert(*s == 0);

  s = tx_to(tx_new("a"));
  assert(s[0] == 'a');
  assert(s[1] == 0);

  s = tx_to(tx_new("xyz"));
  assert(s[0] == 'x');
  assert(s[1] == 'y');
  assert(s[2] == 'z');
  assert(s[3] == 0);

  puts("    Finished");
}
