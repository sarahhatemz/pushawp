#include "push_swap.h"

int     main(int ac, char **av)
{
    int     *numbers;
    int     size;
    t_node  *a;
    t_node  *b;

    if (ac < 2)
        return (0);
    numbers = ps_parse_numbers(ac, av);
    if (!numbers)
        return (1);
    size = ps_count_tokens(ac, av);
    a = build_stack(numbers, size);
    free(numbers);
    if (!a)
        return (1);
    b = NULL;
    if (!is_sorted(a))
        sort_small(&a, &b);
    free_stack(&a);
    return (0);
}