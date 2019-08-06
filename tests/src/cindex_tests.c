// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "cindex_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void cindex_tests (void) {
  puts("'cindex' tests:");

  Tx *tx = tx_sub(tx_new("xxxabc"), 3, 3);
  assert(tx_cindex(tx, 'a') == -1);

  tx = tx_sub(tx_new("xxxabc"), 3, 4);
  assert(tx_cindex(tx, 'a') == 0);
  assert(tx_cindex(tx, 'b') == -1);

  tx = tx_sub(tx_new("xxxabc"), 3, 6);
  assert(tx_cindex(tx, 'a') == 0);
  assert(tx_cindex(tx, 'b') == 1);
  assert(tx_cindex(tx, 'c') == 2);
  assert(tx_cindex(tx, 'd') == -1);

  puts("    Finished");
}
