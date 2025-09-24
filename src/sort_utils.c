/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:51:15 by texenber          #+#    #+#             */
/*   Updated: 2025/09/24 11:52:28 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_target_in_b(t_stack_node *b, t_stack_node *current)
{
	t_stack_node	*target;
	t_stack_node	*tmp;
	int	min;
	int max;
	
	target = NULL;
	tmp = b;
	min = 0;
	max = 0;

	while(tmp)
	{
		if (tmp->nb > current->nb)
		{
			min = tmp->nb;
			target = tmp;
		}
		if (tmp->nb < current->nb)
		{
			
		}
	}
	
	if 
}
	
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
	t_stack_node *target;
	
	target = find_target_in_b(b, current);
}