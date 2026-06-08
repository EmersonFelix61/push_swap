#include "../includes/push_swap.h"

int stack_size(t_stack *stack)
{
  int count;

  count = 0;
  while(stack)
  {
    count++;
    stack=stack->next;
  }
  return (count);
}

int is_sorted(t_stack *stack)
{
 if (!stack || !stack->next)
  return (1);
 while (stack->next)
 {
  if ((stack->value) > (stack->next->value))
    return (0);
  stack = stack->next;
} 
return (1);
}

int find_lowest(t_stack *stack)
{
  int lowest;
  int i;
  int lowest_i;
  
  if (!stack)
    return (0);
  lowest = stack->value;
  i = 0;
  lowest_i = 0;
  while (stack)
  {
    if (stack->value < lowest)
    {
      lowest = stack->value;
      lowest_i = i;
    }
    i++;
    stack = stack->next;
  }
  return (lowest_i);
}

int find_highest(t_stack *stack)
{
  int highest;
  int i;
  int highest_i;

  if (!stack)
    return (0);
  highest = stack->value;
  i = 0;
  highest_i = 0;
  while (stack)
  {
    if (stack->value > highest)
    {
      highest = stack->value;
      highest_i = i;
    }
    i++;
    stack = stack->next;
  }
  return (highest_i);
}