
/*
 * file: queue.c
 * Author: Basu
 * Date: 08/01/2016
 *
*/

#include<stdio.h>
#include<stdlib.h>

#include "queue.h"


queue_t *create_queue(int size)
{
  queue_t *queue_head;
  
  if (size <= 0)
  {
    printf("Invalid size %d for queue\n", size);
    return NULL;
  }
  
  queue_head = (queue_t*)malloc( sizeof(queue_t) );
  
  if (!queue_head)
  {
    return NULL;
  }
  
  queue_head->data_ptr = (int*)malloc( size * sizeof(int) );
  
  if (!queue_head->data_ptr)
  {
    free(queue_head);
    return NULL;
  }
  
  queue_head->head = -1;
  queue_head->tail = -1;
  queue_head->size = size;
  
  return(queue_head);
}


void destroy_queue(queue_t *queue_head)
{
  if (!queue_head)
  {
    return;
  }
  
  if (queue_head->data_ptr)
  {
    free(queue_head->data_ptr);
  }
  
  queue_head->data_ptr = NULL;
  
  free(queue_head);
  
  queue_head = NULL;
}


int eneque(queue_t *queue_head, int data)
{
  if (!queue_head)
  {
    return -1;
  }
  
  if (!queue_head->data_ptr)
  {
    return -1;
  }
  
  if ( is_queue_full(queue_head) )
  {
    return -1;
  }
  
  /*wrap around if reached end*/
  queue_head->tail++;

  if ( queue_head->tail == queue_head->size ) 
  {
    queue_head->tail = 0;
  }
  
  queue_head->data_ptr[queue_head->tail] = data;
  
  return 0; 
}


int dequeue(queue_t *queue_head, int *data)
{
  
  if (!queue_head)
  {
    return -1;
  }
  
  if (!queue_head->data_ptr)
  {
    return -1;
  }

  if (queue_head->head == queue_head->tail)
  {
    return -1;
  }

  if ( is_queue_empty(queue_head) )
  {
    return -1;
  }  
    
  queue_head->head++;
  
  if ( queue_head->head == queue_head->size ) 
  {
    queue_head->head = 0;
  }
    
  *data = queue_head->data_ptr[queue_head->head];
  
  return 0;
}


int retrieve_queue(queue_t *queue_head, int *data)
{

  int head;
  
  if (!queue_head)
  {
    return -1;
  }
  
  if (!queue_head->data_ptr)
  {
    return -1;
  }

  if (queue_head->head == queue_head->tail)
  {
    return -1;
  }
  
  if ( is_queue_empty(queue_head) )
  {
    return -1;
  }
  
  head = queue_head->head;
  head++;
  
  if ( head == queue_head->size ) 
  {
    head = 0;
  }
  
  *data = queue_head->data_ptr[head];
  
  return 0;
}


bool is_queue_empty(queue_t *queue_head)
{
  if (!queue_head)
  {
    return true;
  }
  
  if (!queue_head->data_ptr)
  {
    return true;
  }

  if (queue_head->head == queue_head->tail)
  {
    return true;
  }
  
  return false;
}


bool is_queue_full(queue_t *queue_head)
{
  if (!queue_head)
  {
    return true;
  }
  
  if (!queue_head->data_ptr)
  {
    return true;
  }
  
  if ( (queue_head->tail - queue_head->size) == queue_head->head )
  {
    return true;
  }
  
  return false;
}


