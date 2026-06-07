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