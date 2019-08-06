// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "left_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void left_tests (void) {
  puts("'left' tests:");

  Tx *tx0 = tx_new("");
  assert(tx_eq(tx0, tx_left(tx0, 0)));

  Tx *tx1 = tx_new("a");
  assert(tx_eq(tx0, tx_left(tx1, 0)));
  assert(tx_eq(tx1, tx_left(tx1, 1)));

  Tx *tx = tx_new("abc");
  assert(tx_eq(tx0, tx_left(tx, 0)));
  assert(tx_eq(tx1, tx_left(tx, 1)));
  assert(tx_eq(tx_new("ab"), tx_left(tx, 2)));
  assert(tx_eq(tx, tx_left(tx, 3)));

  puts("    Finished");
}
