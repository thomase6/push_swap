/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:51:15 by texenber          #+#    #+#             */
/*   Updated: 2025/10/01 09:04:44 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack_node *b, t_stack_node *cheapest_node)
{
	t_stack_node	*current;

	current = b;
	while (current)
	{
		if (current == cheapest_node)
			current->cheapest = true;
		current = current->next;
	}
}

void	assign_index(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

static int	find_smallest_index(t_stack_node *stack)
{
	int	min;
	int	min_index;

	min_index = -1;
	min = INT_MAX;
	while (stack)
	{
		if (stack->nb < min)
		{
			min_index = stack->index;
			min = stack->nb;
		}
		stack = stack->next;
	}
	if (min_index == -1)
	{
		ft_printf("issues in find_smallest_index");
		exit(EXIT_FAILURE);
	}
	return (min_index);
}

int	assign_target_index(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*head;
	t_stack_node	*tmp;
	int				target_index;
	int				min;

	head = a;
	tmp = head;
	min = INT_MAX;
	target_index = -1;
	while (tmp)
	{
		if (tmp->nb > b->nb && (tmp->nb - b->nb) < min)
		{
			min = tmp->nb - b->nb;
			target_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (target_index == -1)
		target_index = find_smallest_index(a);
	return (target_index);
}

void	final_rotate(t_stack_node **a)
{
	t_stack_node	*min_node;
	int				i;
	int				stack_size;

	assign_index(*a);
	min_node = find_min_node(*a);
	stack_size = stack_len(*a);
	i = min_node->index;
	if (i <= stack_size / 2)
	{
		while (i--)
			ra(a);
	}
	else
	{
		i = stack_size - i;
		while (i--)
			rra(a);
	}
}
