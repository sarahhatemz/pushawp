#include "push_swap.h"

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

int	find_min_position(t_node *a)
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

static void	sort_3_cases(t_node **a, int f, int s, int t)
{
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

void	assign_ranks(t_node *a, int size)
{
	int		*tmp;
	int		i;
	t_node	*cur;

	tmp = malloc(size * sizeof(int));
	if (!tmp)
		return ;
	cur = a;
	i = 0;
	while (cur)
	{
		tmp[i++] = cur->value;
		cur = cur->next;
	}
	sort_tmp(tmp, size);
	cur = a;
	while (cur)
	{
		i = 0;
		while (tmp[i] != cur->value)
			i++;
		cur->rank = i;
		cur = cur->next;
	}
	free(tmp);
}

static int	get_max_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_node **a, t_node **b, int size)
{
	int	bit;
	int	i;

	assign_ranks(*a, size);
	bit = 0;
	while (bit < get_max_bits(size))
	{
		i = size;
		while (i--)
		{
			if (!(((*a)->rank >> bit) & 1))
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
		bit++;
	}
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
	else
		radix_sort(a, b, size);
}