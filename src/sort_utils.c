/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:51:15 by texenber          #+#    #+#             */
/*   Updated: 2025/09/25 13:48:00 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void assign_index(t_stack_node *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}
static int	find_smallest_index(t_stack_node *stack)
{
	int	min;
	int min_index;
	
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
	while(tmp)
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

int	calculate_a_cost(t_stack_node *a, t_stack_node *current)
{
	int	a_len;
	int	current_pos;
	int	a_cost;
	t_stack_node	*tmp; 
	
	tmp = a;
	current_pos = 0;
	a_len = stack_len(a);
	while (tmp)
	{
		if (tmp->nb == current->nb)
			break;
		current_pos++;
		tmp = tmp->next;
	}
	if (current_pos <= a_len / 2)
		a_cost = current_pos;
	else if (current_pos > a_len / 2)
		a_cost = a_len - current_pos;
	return (a_cost);
}

int	calculate_b_cost(t_stack_node *b, t_stack_node *current)
{
	t_stack_node	*target;
	int				b_cost;
	
	b_cost = 0;
	// target = find_target_in_b(b, current);
	return (b_cost);
}