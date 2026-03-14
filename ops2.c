#include"push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;

	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}
void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	first->next = NULL;

	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "rb\n", 3);
}
void	rra(t_node **a)
{
	t_node	*last;
	t_node	*before_last;

	if (!*a || !(*a)->next)
		return ;
	before_last = NULL;
	last = *a;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}
void	rrb(t_node **b)
{
	t_node	*last;
	t_node	*before_last;

	if (!*b || !(*b)->next)
		return ;
	before_last = NULL;
	last = *b;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}
