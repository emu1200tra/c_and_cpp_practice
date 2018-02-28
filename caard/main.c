#include <stdio.h>
#include "card.h"

int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;

  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  //EOF­n«öctr z
  shuffle(deck);
  print(deck);
  return 0;
}
