/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:49:20 by texenber          #+#    #+#             */
/*   Updated: 2025/09/15 14:32:34 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node *stack)
{	
	int	tmp;
	if (!stack || !stack->next)
		return;
	tmp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = tmp;
}

void	sa(t_stack_node *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node *a, t_stack_node *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}