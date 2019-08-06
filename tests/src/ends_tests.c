// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "ends_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void ends_tests (void) {
  puts("'ends' tests:");

  Tx *tx = tx_sub(tx_new("xxxabc"), 3, 3);
  assert(tx_ends(tx, ""));
  assert(!tx_ends(tx, "a"));

  tx = tx_sub(tx_new("xxxabc"), 3, 4);
  assert(tx_ends(tx, ""));
  assert(tx_ends(tx, "a"));
  assert(!tx_ends(tx, "b"));
  assert(!tx_ends(tx, "ab"));

  tx = tx_sub(tx_new("xxxabc"), 3, 6);
  assert(tx_ends(tx, ""));
  assert(tx_ends(tx, "c"));
  assert(!tx_ends(tx, "b"));
  assert(tx_ends(tx, "bc"));
  assert(tx_ends(tx, "abc"));
  assert(!tx_ends(tx, "abcd"));
  assert(!tx_ends(tx, "bbc"));

  puts("    Finished");
}
