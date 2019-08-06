// Copyright 05-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#ifndef DMC_TX_H
  #define DMC_TX_H

///
typedef struct tx_Tx Tx;

///
Tx *tx_new (char *s);

///
int tx_length (Tx *this);

///
int tx_eq (Tx *tx1, Tx *tx2);

///
char *tx_to (Tx *this);

/// Ranges are 0 >= begin >= end <= tx_length(this)
Tx *tx_sub (Tx *this, int begin, int end);

/// Equals to 'tx_sub(this, begin, tx_length(this));'
Tx *tx_right (Tx *this, int begin);

/// Equals to 'tx_sub(this, 0, end);'
Tx *tx_left (Tx *this, int end);

/// Splits 'this' in 'left' and 'right'. For example:
///   Tx *l; Tx *r; spit(&l, &r, "abc", 2); // -> l = "ab", r = "c".
/// Range of ix is between 0 and tx_length(this)
void tx_split (Tx **left, Tx **right, Tx *this, int ix);

/// Returns '1' or '0' depending on whether 'this' starts with 's' or not.
int tx_starts (Tx *this, char *s);

/// Returns '1' or '0' depending on whether 'this' ends with 's' or not.
int tx_ends (Tx *this, char *s);

/// Returns the index of 'c' in 'this' or -1 if 'c' is not found.
int tx_cindex (Tx *this, char c);

/// Returns the index of 's' in 'this' or -1 if 's' is not found.
int tx_index (Tx *this, char *s);

/// Returns the last index of 'c' in 'this' or -1 if 'c' is not found.
int tx_clast_index (Tx *this, char c);

/// Returns the last index of 's' in 'this' or -1 if 's' is not found.
int tx_last_index (Tx *this, char *s);

/// Returns index and character corresponding to the first occurence of a
/// character of 'cs' in 'this'. For example:
///   Tx *tx = tx_sub(tx_new("xxxabc"), 3, 6);
///   int ix;
///   char c;
///   tx_cindexes(&ix, &c, tx, "bac");
///   assert(ix == 0);
///   assert(c == 'a');
void tx_cindexes (int *ix, char *c, Tx *this, char *cs);

/// Returns index and string corresponding to the first occurence of a
/// string of 'ss' (char *[] NULL ended) in 'this'. For example:
///   tx = tx_sub(tx_new("xxxabc"), 3, 6);
///   int ix;
///   char *s;
///   tx_indexes(&ix, &s, tx, (char *[]){"b", "ab", "c", NULL});
///   assert(ix == 0);
///   assert(s[0] == 'a' && s[1] == 'b' && s[2] == 0);
void tx_indexes (int *ix, char **s, Tx *this, char **ss);

#endif
