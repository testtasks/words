#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char alphabet[] = "ab"; // "abcdefghijklmnopqrstuvwxyz";
static int n = sizeof(alphabet) - 1;

// Size of a word
static int k = 4;

// Contains indices of chars in alphabet
// length == k
// Any possible value if indices corresponds to some word from alphabet
static int * indices = NULL;

// Calculates lexicographically next value of indices unless it's finished
int tryIncrement() {
  for (int i=k-1; i>=0; --i) {
    if (indices[i] < n - 1) {
      indices[i] += 1;
      for (int j=k-1; j>i; --j) {
	indices[j] = 0;
      }
      return 1;
    }
  }
  return 0;
}

// Iterates words in order according to tryIncrement
void iterateWords(void (*wordHandler)(char *)) {
  indices = malloc(k*sizeof(int));
  memset(indices, 0, k*sizeof(int));
  
  char * word = malloc(k + 1);
  word[k] = '\0';

  do {
    for (int i=0; i<k; ++i) {
      sprintf(&(word[i]), "%c", alphabet[indices[i]]);
    }
    wordHandler(word);
  } while (tryIncrement());
}

void printWord(char * word) {
  printf("%s\n", word);
}

int main(int argc, char ** argv) {
  iterateWords(printWord);

  return 0;
}
