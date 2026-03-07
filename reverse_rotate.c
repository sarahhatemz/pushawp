#include"push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	before_last = NULL;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}