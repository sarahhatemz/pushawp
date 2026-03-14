#include "push_swap.h"

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
	sort_3_cases(a, f, s, t);
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

static void	rotate_min_to_top(t_node **a)
{
	int	pos;
	int	size;

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
}

void	sort_5(t_node **a, t_node **b)
{
	if (!a || !(*a) || stack_size(*a) < 5)
		return ;
	rotate_min_to_top(a);
	pb(a, b);
	rotate_min_to_top(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

static void	sort_tmp(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

