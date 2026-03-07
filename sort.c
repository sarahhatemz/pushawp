#include"push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

static int	find_min_position(t_node *a)
{
	int	pos;
	int	i;
	int	min;

	if (!a)
		return (0);
	min = a->value;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

void	sort_2(t_node **a)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_3(t_node **a)
{
	int	f;
	int	s;
	int	t;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}

void	sort_4(t_node **a, t_node **b)
{
	int	pos;

	if (!a || !(*a) || stack_size(*a) < 4)
		return ;
	pos = find_min_position(*a);
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_node **a, t_node **b)
{
	int	pos;
	int	size;
	int	i;

	if (!a || !(*a) || stack_size(*a) < 5)
		return ;
	i = 0;
	while (i < 2)
	{
		pos = find_min_position(*a);
		size = stack_size(*a);
		while (pos > 0)
		{
			if (pos <= size / 2)
				ra(a);
			else
				rra(a);
			pos = find_min_position(*a);
			size = stack_size(*a);
		}
		pb(a, b);
		i++;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
void	sort_small(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}