
/*
 * file: random_utils.c
 * Author: Basu
 * Date: 07/31/2016
 *
*/

#include<stdio.h>
#include<stdlib.h>

#include "random_utils.h"

int* generate_random_numbers(int size)
{
  
  int i;
  int *random_numbers_p = (int*)malloc( size * sizeof(int) );

    if (random_numbers_p)
    {
      for (i = 0; i < size; i++)
     {
       srand(rand());
       random_numbers_p[i] = rand() % 100;    
        //printf("%d = %d\n", i, random_numbers_p[i]);
     } 

    return (random_numbers_p);
    }
  
  
  return (NULL);

}


void destroy_random_numbers(int *random_numbers_p)
{
  free(random_numbers_p);
}
