
/*
 * file: gtest.cpp
 * Author: Basu
 * Date: 07/31/2016
 *
*/

#include <gtest/gtest.h>

#include "sort_utils.h"
#include "random_utils.h"

#define SIZE 1000

//int random_numbers_p[] = {79, 23, 82, 70, 95};

TEST(SORT, random_numbers) 
{
  int *random_numbers_p = NULL;
  
  random_numbers_p = generate_random_numbers(SIZE);

  free(random_numbers_p);
}


TEST(SORT, bubble_sort) 
{

  int *random_numbers_p = NULL;
  int *sorted_p = NULL;

  random_numbers_p = generate_random_numbers(SIZE);

  sorted_p = bubble_sort(random_numbers_p, SIZE);

  EXPECT_EQ( 0, validate_sort(sorted_p, SIZE) );

  free(sorted_p);
  free(random_numbers_p);
}


TEST(SORT, insertion_sort) 
{

  int *random_numbers_p = NULL;
  int *sorted_p = NULL;

  random_numbers_p = generate_random_numbers(SIZE);

  sorted_p = insertion_sort(random_numbers_p, SIZE);

  EXPECT_EQ( 0, validate_sort(sorted_p, SIZE) );

  free(sorted_p);
  free(random_numbers_p);
}


TEST(SORT, selection_sort) 
{

  int *random_numbers_p = NULL;
  int *sorted_p = NULL;

  random_numbers_p = generate_random_numbers(SIZE);

  sorted_p = selection_sort(random_numbers_p, SIZE);

  EXPECT_EQ( 0, validate_sort(sorted_p, SIZE) );

  free(sorted_p);
  free(random_numbers_p);
}


TEST(SORT, quick_sort) 
{

  int *random_numbers_p = NULL;
  int *sorted_p = NULL;

  random_numbers_p = generate_random_numbers(SIZE);

  sorted_p = quick_sort(random_numbers_p, SIZE);

  EXPECT_EQ( 0, validate_sort(sorted_p, SIZE) );
   
  free(sorted_p);
  free(random_numbers_p);
}


TEST(SORT, merge_sort) 
{

  int *random_numbers_p = NULL;
  int *sorted_p = NULL;
  
  random_numbers_p = generate_random_numbers(SIZE);

  sorted_p = merge_sort(random_numbers_p, SIZE);

  EXPECT_EQ( 0, validate_sort(sorted_p, SIZE) );
   
  free(sorted_p);
  free(random_numbers_p);
}


int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
