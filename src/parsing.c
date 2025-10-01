/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:22:29 by texenber          #+#    #+#             */
/*   Updated: 2025/10/01 09:20:59 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_duplicate(t_stack_node *a, int n)
{
	while (a)
	{
		if (a->nb == n)
			return (true);
		a = a->next;
	}
	return (false);
}

static long	ft_atol(const char *str)
{
	int		i;
	long	sum;
	int		sign;

	i = 0;
	sum = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		sum = ((sum * 10) + (str[i] - '0'));
		i++;
	}
	return (sum * sign);
}

static bool	is_valid_int(const char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	add_node(t_stack_node **stack, int n)
{
	t_stack_node	*current;
	t_stack_node	*end_node;

	if (!stack)
		return ;
	current = malloc(sizeof(t_stack_node));
	if (!current)
	{
		ft_free_stack(stack);
		ft_error_exit();
	}
	current->next = NULL;
	current->nb = n;
	if (!(*stack))
	{
		*stack = current;
		current->prev = NULL;
	}
	else
	{
		end_node = find_end(*stack);
		end_node->next = current;
		current->prev = end_node;
	}
}

void	init_stack(t_stack_node **a, char **split_args)
{
	int		i;
	long	n;

	i = 0;
	while (split_args[i])
	{
		if (!is_valid_int(split_args[i]) || !too_many_0(split_args[i]))
		{
			ft_free_args(split_args, a);
			ft_error_exit();
		}
		n = ft_atol(split_args[i]);
		if (n < INT_MIN || n > INT_MAX)
		{
			ft_free_args(split_args, a);
			ft_error_exit();
		}
		if (is_duplicate(*a, (int)n))
		{
			ft_free_args(split_args, a);
			ft_error_exit();
		}
		add_node(a, (int)n);
		i++;
	}
}
