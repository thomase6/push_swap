/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:22:29 by texenber          #+#    #+#             */
/*   Updated: 2025/09/12 15:11:52 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(const char *str, int *i)
{	
	int	sign;
	
	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static long	ft_atol(const char *str)
{
	int		i;
	long	sum;
	int		sign;
	
	i = 0;
	sum = 0;
	sign = get_sign(str, &i);
	while (str[i])
	{
		sum = ((sum * 10) + (str[i] - '0'));
		i++;
	}
	return (sum * sign);
}

static bool	is_valid_int(const char *str)
{
	int		i;
	long	val;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if(!ft_isdigit(str[i]))
		return false;
	while (str[i])
	{
		if(!ft_isdigit(str[i]))
			return false;
		i++;
	}
	if (ft_strlen(str) > 11)// this doesn't cover leading zeros
		return false;
	val = ft_atol(str);
	if (val < INT_MIN || val > INT_MAX)
		return false;
	return true;
}

t_stack	*init_stack(char **split_args)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (split_args[count])
		count++;
	while (split_args[i])
	{
		if (!is_valid_int(split_args[i]))
		{
			ft_free_args(split_args);
			ft_error_exit(3);
		}
		i++;
	}
}
