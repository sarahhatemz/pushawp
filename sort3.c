#include"push_swap.h"
static int  get_max_bits(int size)
{
    int bits;
    int max;

    bits = 0;
    max = size - 1;
    while (max > 0)
    {
        max >>= 1;
        bits++;
    }
    return (bits);
}
void    radix_sort(t_node **a, t_node **b, int size)
{
    int     bit;
    int     i;

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
void    sort_small(t_node **a, t_node **b)
{
    int size;

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