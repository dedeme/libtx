// Copyright 06-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "cindexes_tests.h"
#include <assert.h>
#include <stdio.h>
#include <gc.h>
#include "dmc/Tx.h"

void cindexes_tests (void) {
  puts("'cindexes' tests:");

  int ix;
  char c;

  Tx *tx = tx_sub(tx_new("xxxabc"), 3, 3);
  tx_cindexes(&ix, &c, tx, "");
  assert(ix == -1);
  assert(c == 0);
  tx_cindexes(&ix, &c, tx, "b");
  assert(ix == -1);
  assert(c == 0);
  tx_cindexes(&ix, &c, tx, "bac");
  assert(ix == -1);
  assert(c == 0);

  tx = tx_sub(tx_new("xxxabc"), 3, 4);
  tx_cindexes(&ix, &c, tx, "");
  assert(ix == -1);
  assert(c == 0);
  tx_cindexes(&ix, &c, tx, "b");
  assert(ix == -1);
  assert(c == 0);
  tx_cindexes(&ix, &c, tx, "bac");
  assert(ix == 0);
  assert(c == 'a');

  tx = tx_sub(tx_new("xxxabc"), 3, 6);
  tx_cindexes(&ix, &c, tx, "");
  assert(ix == -1);
  assert(c == 0);
  tx_cindexes(&ix, &c, tx, "b");
  assert(ix == 1);
  assert(c == 'b');
  tx_cindexes(&ix, &c, tx, "cb");
  assert(ix == 1);
  assert(c == 'b');
  tx_cindexes(&ix, &c, tx, "bac");
  assert(ix == 0);
  assert(c == 'a');

  puts("    Finished");
}
