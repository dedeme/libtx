// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "split_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void split_tests (void) {
  puts("'split' tests:");

  Tx *l;
  Tx *r;

  tx_split(&l, &r, tx_new(""), 0);
  assert(tx_eq(tx_new(""), l));
  assert(tx_eq(tx_new(""), r));

  tx_split(&l, &r, tx_new("a"), 0);
  assert(tx_eq(tx_new(""), l));
  assert(tx_eq(tx_new("a"), r));

  tx_split(&l, &r, tx_new("a"), 1);
  assert(tx_eq(tx_new("a"), l));
  assert(tx_eq(tx_new(""), r));

  tx_split(&l, &r, tx_new("xyz"), 0);
  assert(tx_eq(tx_new(""), l));
  assert(tx_eq(tx_new("xyz"), r));

  tx_split(&l, &r, tx_new("xyz"), 1);
  assert(tx_eq(tx_new("x"), l));
  assert(tx_eq(tx_new("yz"), r));

  tx_split(&l, &r, tx_new("xyz"), 2);
  assert(tx_eq(tx_new("xy"), l));
  assert(tx_eq(tx_new("z"), r));

  tx_split(&l, &r, tx_new("xyz"), 3);
  assert(tx_eq(tx_new("xyz"), l));
  assert(tx_eq(tx_new(""), r));

  puts("    Finished");
}
