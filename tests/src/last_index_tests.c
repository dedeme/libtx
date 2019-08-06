// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "last_index_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void last_index_tests (void) {
  puts("'last_index' tests:");

  Tx *tx = tx_sub(tx_new("xxxabc"), 3, 3);
  assert(tx_last_index(tx, "") == 0);
  assert(tx_last_index(tx, "a") == -1);

  tx = tx_sub(tx_new("xxxabc"), 3, 4);
  assert(tx_last_index(tx, "") == 1);
  assert(tx_last_index(tx, "a") == 0);
  assert(tx_last_index(tx, "ab") == -1);
  assert(tx_last_index(tx, "b") == -1);

  tx = tx_sub(tx_new("xxxabcab"), 3, 8);
  assert(tx_last_index(tx, "") == 5);
  assert(tx_last_index(tx, "a") == 3);
  assert(tx_last_index(tx, "b") == 4);
  assert(tx_last_index(tx, "c") == 2);
  assert(tx_last_index(tx, "d") == -1);
  assert(tx_last_index(tx, "bc") == 1);
  assert(tx_last_index(tx, "abc") == 0);
  assert(tx_last_index(tx, "ac") == -1);
  assert(tx_last_index(tx, "ab") == 3);

  puts("    Finished");
}
