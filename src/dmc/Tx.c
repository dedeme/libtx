// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/Tx.h"
#include <gc.h>
#include <stdlib.h>
#include <execinfo.h>
#include <string.h>
#include <stdio.h>

static void fail () {
  void *array[15];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 15);
  strings = backtrace_symbols (array, size);

  printf("\nObtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++)
     printf("  %s\n", strings[i]);

  free(strings);

  exit(1);
}

struct tx_Tx {
  char *s;
  int begin;
  int end;
};

static Tx *new (char *s, int begin, int end) {
  Tx *this = GC_MALLOC(sizeof(Tx));
  this->s = s;
  this->begin = begin;
  this->end = end;
  return this;
}

Tx *tx_new (char *s) {
  return new(s, 0, strlen(s));
}

int tx_length (Tx *this) {
  return this->end - this->begin;
}

int tx_eq (Tx *tx1, Tx *tx2) {
  int len = tx_length(tx1);
  if (len != tx_length(tx2)) {
    return 0;
  }
  char *p1 = tx1->s + tx1->begin;
  char *p2 = tx2->s + tx2->begin;
  char *pend = tx1->s + tx1->end;
  while (p1 < pend) {
    if (*p1++ != *p2++) {
      return 0;
    }
  }
  return 1;
}

char *tx_to (Tx *this) {
  int len = tx_length(this);
  char *r = GC_MALLOC_ATOMIC(len + 1);
  r[len] = 0;
  memcpy(r, this->s + this->begin, len);
  return r;
}

Tx *tx_sub (Tx *this, int begin, int end) {
  if (begin < 0) {
    printf("tx_sub: begin (%d) < 0", begin);
    fail();
  }
  if (end > tx_length(this)) {
    printf("tx_sub: end (%d) > tx_length (%d)", end, tx_length(this));
    fail();
  }
  if (begin > end) {
    printf("tx_sub: begin (%d) > end (%d)", begin, end);
    fail();
  }
  return new(this->s, this->begin + begin, this->begin + end);
}

Tx *tx_right (Tx *this, int begin){
  if (begin < 0) {
    printf("tx_right: begin (%d) < 0", begin);
    fail();
  }
  if (begin > tx_length(this)) {
    printf("tx_right: begin (%d) > tx_length (%d)", begin, tx_length(this));
    fail();
  }
  return new(this->s, this->begin + begin, this->end);
}

Tx *tx_left (Tx *this, int end) {
  if (end < 0) {
    printf ("tx_left: end (%d) < 0", end);
    fail();
  }
  if (end > tx_length(this)) {
    printf ("tx_left: end (%d) > tx_length (%d)", end, tx_length(this));
    fail();
  }
  return new(this->s, this->begin, this->begin + end);
}

void tx_split (Tx **left, Tx **right, Tx *this, int ix) {
  if (ix < 0) {
    printf("tx_split: ix (%d) < 0", ix);
    fail();
  }
  if (ix > tx_length(this)) {
    printf("tx_split: ix (%d) > tx_length (%d)", ix, tx_length(this));
    fail();
  }

  *left = tx_left(this, ix);
  *right = tx_right(this, ix);
}

int tx_starts (Tx *this, char *s) {
  Tx *tx = tx_new(s);
  int len = tx_length(tx);
  if (tx_length(this) < len) {
    return 0;
  }
  return tx_eq(tx_left(this, len), tx);
}

int tx_ends (Tx *this, char *s) {
  Tx *tx = tx_new(s);
  int l = tx_length(this);
  int len = tx_length(tx);
  if (l < len) {
    return 0;
  }
  return tx_eq(tx_right(this, l - len), tx);
}

int tx_cindex (Tx *this, char c) {
  char *p = this->s + this->begin;
  char *pend = this->s + this->end;
  int i = 0;
  while (p < pend) {
    if (*p++ == c) {
      return i;
    }
    ++i;
  }
  return -1;
}

int tx_index (Tx *this, char *s) {
  Tx *tx = tx_new(s);
  int len = tx_length(tx);
  for (int i = 0, j = len; i <= tx_length(this) - len; ++i, ++j) {
    if (tx_eq(tx_sub(this, i, j), tx)) {
      return i;
    }
  }
  return -1;
}

int tx_clast_index (Tx *this, char c) {
  char *p = this->s + this->begin;
  char *pend = this->s + this->end;
  int i = 0;
  int r = -1;
  while (p < pend) {
    if (*p++ == c) {
      r = i;
    }
    ++i;
  }
  return r;
}

int tx_last_index (Tx *this, char *s) {
  Tx *tx = tx_new(s);
  int len = tx_length(tx);
  int r = -1;
  for (int i = 0, j = len; i <= tx_length(this) - len; ++i, ++j) {
    if (tx_eq(tx_sub(this, i, j), tx)) {
      r = i;
    }
  }
  return r;
}

void tx_cindexes (int *ix, char *c, Tx *this, char *cs) {
  *ix = -1;
  *c = 0;

  while (*cs) {
    char ch = *cs++;
    int i = tx_cindex(this, ch);
    if (i > -1) {
      if (*ix == -1 || i < *ix) {
        *ix = i;
        *c = ch;
      }
    }
  }
}

void tx_indexes (int *ix, char **s, Tx *this, char **ss) {
  *ix = -1;
  *s = "";

  while (*ss) {
    char *st = *ss++;
    int i = tx_index(this, st);
    if (i > -1) {
      if (*ix == -1 || i < *ix) {
        *ix = i;
        *s = st;
      }
    }
  }
}
