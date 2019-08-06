// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "eq_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"


void eq_tests (void) {
  puts("'eq' tests:");

  Tx *tx0 = tx_new("");
  Tx *tx1 = tx_new("a");
  Tx *tx = tx_new("xyz");
  Tx *tx2 = tx_new("xyz");

  assert(tx_eq(tx0, tx0));
  assert(tx_eq(tx1, tx1));
  assert(tx_eq(tx, tx));
  assert(tx_eq(tx2, tx));
  assert(tx_eq(tx, tx2));

  assert(!tx_eq(tx0, tx1));
  assert(!tx_eq(tx0, tx));

  assert(!tx_eq(tx1, tx0));
  assert(!tx_eq(tx1, tx));

  assert(!tx_eq(tx, tx0));
  assert(!tx_eq(tx, tx1));

  puts("    Finished");
}
