// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "right_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"


void right_tests (void) {
  puts("'right' tests:");

  Tx *tx0 = tx_new("");
  assert(tx_eq(tx0, tx_right(tx0, 0)));

  Tx *tx1 = tx_new("a");
  assert(tx_eq(tx1, tx_right(tx1, 0)));
  assert(tx_eq(tx0, tx_right(tx1, 1)));

  Tx *tx = tx_new("abc");
  assert(tx_eq(tx, tx_right(tx, 0)));
  assert(tx_eq(tx_new("bc"), tx_right(tx, 1)));
  assert(tx_eq(tx_new("c"), tx_right(tx, 2)));
  assert(tx_eq(tx0, tx_right(tx, 3)));

  puts("    Finished");
}
