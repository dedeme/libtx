// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "index_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void index_tests (void) {
  puts("'index' tests:");

  Tx *tx = tx_sub(tx_new("xxxabc"), 3, 3);
  assert(tx_index(tx, "") == 0);
  assert(tx_index(tx, "a") == -1);

  tx = tx_sub(tx_new("xxxabc"), 3, 4);
  assert(tx_index(tx, "") == 0);
  assert(tx_index(tx, "a") == 0);
  assert(tx_index(tx, "ab") == -1);
  assert(tx_index(tx, "b") == -1);

  tx = tx_sub(tx_new("xxxabc"), 3, 6);
  assert(tx_index(tx, "") == 0);
  assert(tx_index(tx, "a") == 0);
  assert(tx_index(tx, "b") == 1);
  assert(tx_index(tx, "c") == 2);
  assert(tx_index(tx, "d") == -1);
  assert(tx_index(tx, "bc") == 1);
  assert(tx_index(tx, "abc") == 0);
  assert(tx_index(tx, "ac") == -1);

  puts("    Finished");
}

