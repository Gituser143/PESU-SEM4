//Header file for session1_seq_search.c

//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.
struct strg {
  char s[20];
};

int seqsearch(struct strg *arr, int n, char *key);
