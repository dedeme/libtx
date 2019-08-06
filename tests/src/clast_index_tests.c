// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "clast_index_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void clast_index_tests (void) {
  puts("'clast_index' tests:");

  Tx *tx = tx_sub(tx_new("xxxabca"), 3, 3);
  assert(tx_clast_index(tx, 'a') == -1);

  tx = tx_sub(tx_new("xxxabca"), 3, 4);
  assert(tx_clast_index(tx, 'a') == 0);
  assert(tx_clast_index(tx, 'b') == -1);

  tx = tx_sub(tx_new("xxxabca"), 3, 7);
  assert(tx_clast_index(tx, 'a') == 3);
  assert(tx_clast_index(tx, 'b') == 1);
  assert(tx_clast_index(tx, 'c') == 2);
  assert(tx_clast_index(tx, 'd') == -1);

  puts("    Finished");
}

