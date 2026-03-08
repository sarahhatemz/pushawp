#include"push_swap.h"
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

static void sort_tmp(int *arr, int size)
{
    int i;
    int j;
    int tmp;

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

void    assign_ranks(t_node *a, int size)
{
    int     *tmp;
    int     i;
    t_node  *cur;

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
