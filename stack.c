/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <salzghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:30:32 by salzghou          #+#    #+#             */
/*   Updated: 2026/03/15 13:30:32 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_node	*build_stack(int *numbers, int count)
{
	int		i;
	t_node	*node;
	t_node	*stack;

	i = 0;
	stack = NULL;
	while (i < count)
	{
		node = new_node(numbers[i]);
		add_back(&stack, node);
		i++;
	}
	return (stack);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
