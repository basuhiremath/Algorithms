
/*
 * file: sort_utils.c
 * Author: Basu
 * Date: 07/31/2016
 *
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#include "sort_utils.h"
#include "queue.h"


#define DEBUG 0


/*---------------------------------------------------------------------------*/
int validate_sort(int *sorted_p, int size)
{
  int i;

  if (!sorted_p)
  {
    return -1;
  }

  for (i = 0; i < (size-1); i++)
  {
    if (sorted_p[i] > sorted_p[i+1])
    {
      return -1;
    }
#if DEBUG
   if ((i < 10) || (i > (size -10)))
   {
     printf("value at %d = %d\n", i, sorted_p[i]);
   }
#endif 
  }

  return 0;
}


/*---------------------------------------------------------------------------*/
void swap(int *x, int *y )
{
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}


/*---------------------------------------------------------------------------*/
void print_numbers(int *random_numbers_p, int low_index, int high_index)
{
  int i;
  
  if (!random_numbers_p)
  {
    return;
  }
  
  printf("----\n");
  for (i = low_index; i < high_index; i++)
  {
    
    printf("value at %d = %d\n", i, random_numbers_p[i] );
  }
  
}

/*---------------------------------------------------------------------------*/
int* bubble_sort(int *random_numbers_p, int size)
{
  
  int i, j;
  int num_operations = 0;

  /*note: to have better error handling*/
  if (!random_numbers_p)
  {
    return NULL;
  }

  int *sorted_p = (int*)malloc(size * sizeof (int));

  if (!sorted_p)
  {
    return NULL;
  }

  memcpy( sorted_p, random_numbers_p, size * sizeof(int) );
  
  for (i = 0; i < size; i++)
  {
    /*last i elements should be sorted; bubble(!)*/
    for (j = 0; j < (size - i - 1); j++)
    {
      num_operations++;
      if (sorted_p[j] > sorted_p[j+1])
      {
        swap( &sorted_p[j], &sorted_p[j+1] );
      }
    }
  }
  
  return (sorted_p);

}


/*---------------------------------------------------------------------------*/
int* insertion_sort(int *random_numbers_p, int size)
{

  int i, j, temp;
  int num_operations = 0;

  /*note: to have better error handling*/
  if (!random_numbers_p)
  {
    return NULL;
  }

  int *sorted_p = (int*)malloc(size * sizeof (int));

  if (!sorted_p)
  {
    return NULL;
  }

  memcpy( sorted_p, random_numbers_p, size * sizeof(int) );
  
  for (i = 1; i < size; i++)
  {
    j = i-1;
    temp = sorted_p[i];
    
    /*insert the element in its correct position; insertion(!)*/
    while ( (j >= 0) && (temp < sorted_p[j]) )
    {
    
      num_operations++;
      
      sorted_p[j+1] = sorted_p[j];
      j--;
    }
    
    sorted_p[j+1] = temp;
     
  }  
  
  return (sorted_p);

}


/*---------------------------------------------------------------------------*/
int* selection_sort(int *random_numbers_p, int size)
{
  int i, j;
  int num_operations = 0;
  int min_j;
  int min_element;

  /*note: to have better error handling*/
  if (!random_numbers_p)
  {
    return NULL;
  }

  int *sorted_p = (int*)malloc(size * sizeof (int));

  if (!sorted_p)
  {
    return NULL;
  }

  memcpy( sorted_p, random_numbers_p, size * sizeof(int) );
  
  for (i = 0; i < (size-1); i++)
  {
  
    /*select the min element; selection(!)*/  
    min_element = sorted_p[i];
    min_j = i;
    
    for (j = i+1; j < size; j++)
    {
    
      num_operations++;
      
      if ( sorted_p[j] < min_element )
      {
        min_element = sorted_p[j];
        min_j = j;
      }
    }
     
    if (min_j != i)
    {
      swap( &sorted_p[i], &sorted_p[min_j] );
    }
        
  }
   
  return (sorted_p);  

}


/*---------------------------------------------------------------------------*/
/*reference: The algorithm design manual, Skiena*/
int quick_sort_partition(int *random_numbers_p, int low_index, int high_index) 
{
  int p;
  
  p = high_index; /*set pivot to be the last element in the item list*/
  
  while ( low_index < high_index )
  {
  
    /*look for the element that is higher than the pivot, starting from left*/
    while ( (random_numbers_p[low_index] < random_numbers_p[p] ) && (low_index < high_index) )
    {
      low_index ++;
    }
    
    /*look for the element that is lower than the pivot, starting from right*/
    while ( (random_numbers_p[high_index] >= random_numbers_p[p] ) && (high_index > low_index) )
    {
      high_index --;
    }
    
    /*swap if different*/
    if (low_index < high_index)
    {
      swap( &random_numbers_p[low_index], &random_numbers_p[high_index] );
    }
    
  }
  
  /*move the pivot to the center of two 'sorted' lists*/
  if (p != high_index)
  {
    swap( &random_numbers_p[p], &random_numbers_p[high_index] );
  }
  
  return(high_index);
  
}


void quick_sort_recursive(int *random_numbers_p, int low_index, int high_index)
{

  int p;
    
  if ( (high_index - low_index) > 0 )
  {
    
    /*find the partition point*/
    p = quick_sort_partition(random_numbers_p, low_index, high_index);
    /*sort lower elements*/
    quick_sort_recursive(random_numbers_p, low_index, p-1);
    /*sort upper element*/
    quick_sort_recursive(random_numbers_p, p+1, high_index);
  }
}


int* quick_sort(int *random_numbers_p, int size)
{
  
  /*note: to have better error handling*/
  if (!random_numbers_p)
  {
    return NULL;
  }

  int *sorted_p = (int*)malloc(size * sizeof (int));

  if (!sorted_p)
  {
    return NULL;
  }

  memcpy( sorted_p, random_numbers_p, size * sizeof(int) );
  
  quick_sort_recursive(sorted_p, 0, size-1);
  
  return (sorted_p);

}


/*---------------------------------------------------------------------------*/
/*reference: The algorithm design manual, Skiena*/
void merge(int *random_numbers_p, int low_index, int middle_index, int high_index)
{
  int i;
  int data_1;
  int data_2;
  queue_t *buffer_1;
  queue_t *buffer_2;
  
  buffer_1 = create_queue(middle_index - low_index + 1);
  buffer_2 = create_queue(high_index - middle_index + 1);
  
  for (i = low_index; i <= middle_index; i++)
  {
    if ( eneque(buffer_1, random_numbers_p[i]) < 0)
    {
      printf("Failed to enqueue in buffer_1\n");
      break;
    }
  }
  
  for (i = middle_index+1; i <= high_index; i++)
  {
    if ( eneque(buffer_2, random_numbers_p[i]) < 0)
    {
      printf("Failed to enqueue in buffer_2\n");
      break;
    }

  }
  
  i = low_index;
  
  /*copy sorted elements into original buffer*/
  while ( !( is_queue_empty(buffer_1) || is_queue_empty(buffer_2) )  )
  {
    
    if (retrieve_queue(buffer_1, &data_1) < 0)
    {
      break;
    }
    if (retrieve_queue(buffer_2, &data_2) < 0)
    {
      break;
    }
    
    if( data_1 <= data_2 )
    {
      if ( dequeue(buffer_1, &random_numbers_p[i]) < 0)
      {
        break;
      }
    }
    else
    {
      if ( dequeue(buffer_2, &random_numbers_p[i]) < 0)
      {
        break;
      }
    }
    
    i++;
    
  }
  
  /*empty both the queues*/
  while ( !( is_queue_empty(buffer_1) ) )
  {
    if ( dequeue(buffer_1, &random_numbers_p[i]) < 0)
    {
      break;
    }
    
    i++;
  }
  
  
  while ( !( is_queue_empty(buffer_2) ) )
  {
    if ( dequeue(buffer_2, &random_numbers_p[i]) < 0)
    {
      break;
    }
    
    i++;
  }
  
  destroy_queue(buffer_1);
  destroy_queue(buffer_2);
    
  return;
  
}

void merge_sort_recursive(int *random_numbers_p, int low_index, int high_index)
{

  int middle_index;
    
  if ( (high_index - low_index) > 0 )
  {
    
    /*find the partition point*/
    middle_index = (low_index + high_index)/2;
    /*lower half*/
    merge_sort_recursive(random_numbers_p, low_index, middle_index);
    /*upper half*/
    merge_sort_recursive(random_numbers_p, middle_index+1, high_index);
    /*merge the halves*/
    merge(random_numbers_p, low_index, middle_index, high_index);
  }
}


int* merge_sort(int *random_numbers_p, int size)
{
  
  /*note: to have better error handling*/
  if (!random_numbers_p)
  {
    return NULL;
  }

  int *sorted_p = (int*)malloc(size * sizeof (int));

  if (!sorted_p)
  {
    return NULL;
  }

  memcpy( sorted_p, random_numbers_p, size * sizeof(int) );
  
  merge_sort_recursive(sorted_p, 0, size-1);
  
  return (sorted_p);

}

/*---------------------------------------------------------------------------*/





