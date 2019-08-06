// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "length_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"


void length_tests (void) {
  puts("'length' tests:");

  Tx *tx = tx_new("");
  assert(tx_length(tx) == 0);

  tx = tx_new("abc");
  assert(tx_length(tx) == 3);

  puts("    Finished");
}

