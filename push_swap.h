#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<unistd.h>
#include<stdlib.h>
# include <limits.h>
# include "libft/libft.h"  



typedef struct s_node
{
    int         value;
    int         rank;
    struct s_node   *next;
}   t_node;



t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
t_node	*build_stack(int *numbers, int count);


void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);


void	ra(t_node **a);
void	rb(t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);


void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);


int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
void	sort_2(t_node **a);
void	sort_3(t_node **a);
void	sort_4(t_node **a, t_node **b);
void	sort_5(t_node **a, t_node **b);
void	sort_small(t_node **a, t_node **b);
void	assign_ranks(t_node *a, int size);
void	radix_sort(t_node **a, t_node **b, int size);


void	ps_free_tokens(char **tokens);
int		ps_count_tokens(int argc, char **argv);
char	**ps_tokenize(int argc, char **argv);
int		check(const char *str);


long	ps_atoi_long(const char *nptr);
int		ps_atoi_checked(const char *s, int *out);
int		*ps_tokens_to_numbers(char **tokens);
int		ps_has_duplicate(int *numbers, int count);
int		ps_tokens_len(char **tokens);


int		*ps_parse_numbers(int argc, char **argv);
int     find_min_position(t_node *a);
void    free_stack(t_node **stack);
#endif
