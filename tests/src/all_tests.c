// Copyright 15-Oct-2018 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/** Version 201904 */

#include "all_tests.h"

#include <stdio.h>
#include <gc.h>

#include "length_tests.h"
#include "eq_tests.h"
#include "to_tests.h"
#include "sub_tests.h"
#include "right_tests.h"
#include "left_tests.h"
#include "split_tests.h"
#include "starts_tests.h"
#include "ends_tests.h"
#include "cindex_tests.h"
#include "index_tests.h"
#include "clast_index_tests.h"
#include "last_index_tests.h"
#include "cindexes_tests.h"
#include "indexes_tests.h"

int main(int argc, char *argv[]) {
/*  length_tests();
  eq_tests();
  to_tests();
  sub_tests();
  right_tests();
  left_tests();
  split_tests();
  starts_tests();
  ends_tests();
  cindex_tests();
  index_tests();
  clast_index_tests();
  last_index_tests();*/
  cindexes_tests();
  indexes_tests();
}
