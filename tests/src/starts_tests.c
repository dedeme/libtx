// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "starts_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void starts_tests (void) {
  puts("'starts' tests:");

  Tx *tx = tx_sub(tx_new("xxxabc"), 3, 3);
  assert(tx_starts(tx, ""));
  assert(!tx_starts(tx, "a"));

  tx = tx_sub(tx_new("xxxabc"), 3, 4);
  assert(tx_starts(tx, ""));
  assert(tx_starts(tx, "a"));
  assert(!tx_starts(tx, "b"));
  assert(!tx_starts(tx, "ab"));

  tx = tx_sub(tx_new("xxxabc"), 3, 6);
  assert(tx_starts(tx, ""));
  assert(tx_starts(tx, "a"));
  assert(!tx_starts(tx, "b"));
  assert(tx_starts(tx, "ab"));
  assert(tx_starts(tx, "abc"));
  assert(!tx_starts(tx, "abcd"));
  assert(!tx_starts(tx, "abd"));

  puts("    Finished");
}
