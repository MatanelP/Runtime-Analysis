#include "osm.h"
#include <iostream>
#include <sys/time.h>
#include "stdlib.h"

void empty_function ()
{}
/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time (unsigned int iterations)
{
  if (iterations == 0) return -1;
  struct timeval start, end;
  gettimeofday (&start, nullptr);
  int x = 0, loop_factor = 10;
  for (unsigned int i = 0; i < iterations; i++)
    {
      x += 1;
      x += 2;
      x += 3;
      x += 4;
      x += 5;
      x += 6;
      x += 7;
      x += 8;
      x += 9;
      x += 10;
    }
  gettimeofday (&end, nullptr);
  return ((double) end.tv_usec - (double) start.tv_usec) * 1000
         / (iterations * loop_factor);
}

/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time (unsigned int iterations)
{
  if (iterations == 0) return -1;
  struct timeval start, end;
  gettimeofday (&start, nullptr);
  int loop_factor = 10;
  for (unsigned int i = 0; i < iterations; i++)
    {
      empty_function ();
      empty_function ();
      empty_function ();
      empty_function ();
      empty_function ();
      empty_function ();
      empty_function ();
      empty_function ();
      empty_function ();
      empty_function ();
    }
  gettimeofday (&end, nullptr);
  return ((double) end.tv_usec - (double) start.tv_usec) * 1000
         / (iterations * loop_factor);
}

/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time (unsigned int iterations)
{
  if (iterations == 0) return -1;
  struct timeval start, end;
  gettimeofday (&start, nullptr);
  int loop_factor = 10;
  for (unsigned int i = 0; i < iterations; i++)
    {
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
      OSM_NULLSYSCALL;
    }
  gettimeofday (&end, nullptr);
  return ((double) end.tv_usec - (double) start.tv_usec) * 1000
         / (iterations * loop_factor);
}

int main (int argc, char *argv[])
{
  int iterations = 2000;
  if (argc == 2)
    {
      iterations = atoi (argv[1]);
    }
  std::cout << "Num of iterations: " << iterations << std::endl;
  std::cout << "Time taken for simple addition in nano seconds: "
            << osm_operation_time (iterations) << std::endl;
  std::cout << "Time taken for empty function call in nano seconds: "
            << osm_function_time (iterations) << std::endl;
  std::cout << "Time taken for system call in nano seconds: "
            << osm_syscall_time (iterations) << std::endl;
  return 0;
}