
/*
 * file: queue.h
 * Author: Basu
 * Date: 08/01/2016
 *
*/

#include <stdio.h>


typedef struct
{
  int *data_ptr;
  int head;
  int tail;
  int size;
} queue_t;

queue_t *create_queue(int size);

void destroy_queue(queue_t *queue_head);

int eneque(queue_t *queue_head, int data);

int dequeue(queue_t *queue_head, int *data);

int retrieve_queue(queue_t *queue_head, int *data);

bool is_queue_empty(queue_t *queue_head);

bool is_queue_full(queue_t *queue_head);







