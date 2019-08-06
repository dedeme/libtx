// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "sub_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"


void sub_tests (void) {
  puts("'sub' tests:");

  Tx *tx0 = tx_new("");
  assert(tx_eq(tx0, tx_sub(tx0, 0, 0)));

  Tx *tx1 = tx_new("a");
  assert(tx_eq(tx0, tx_sub(tx1, 0, 0)));
  assert(tx_eq(tx1, tx_sub(tx1, 0, 1)));
  assert(tx_eq(tx0, tx_sub(tx1, 1, 1)));

  Tx *tx = tx_new("abc");
  assert(tx_eq(tx0, tx_sub(tx, 0, 0)));
  assert(tx_eq(tx1, tx_sub(tx, 0, 1)));
  assert(tx_eq(tx_new("ab"), tx_sub(tx, 0, 2)));
  assert(tx_eq(tx, tx_sub(tx, 0, 3)));

  assert(tx_eq(tx0, tx_sub(tx, 1, 1)));
  assert(tx_eq(tx_new("b"), tx_sub(tx, 1, 2)));
  assert(tx_eq(tx_new("bc"), tx_sub(tx, 1, 3)));

  assert(tx_eq(tx0, tx_sub(tx, 2, 2)));
  assert(tx_eq(tx_new("c"), tx_sub(tx, 2, 3)));

  assert(tx_eq(tx0, tx_sub(tx, 3, 3)));

  puts("    Finished");
}
