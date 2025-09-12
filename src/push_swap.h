/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 07:36:59 by texenber          #+#    #+#             */
/*   Updated: 2025/09/12 10:43:18 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// *** Error identifiers and error messages ****
# define ERR_MEMORY 1
# define ERR_DUPLICATE 2
# define ERR_INPUT 3
# define M_ERROR "Error: Memory allocation failed\n"
# define I_ERROR "Error: Invalid input\n"
# define U_ERROR "Error: Wrong error identifier\n"

# include <stdbool.h>
# include <limits.h>
# include "../include/libft/src/libft.h"
# include "../include/ft_printf/libftprintf.h"
# include <stdio.h>

typedef struct s_stack
{
	int		*data;
	int		index;
	int		size;
	int		capacity;
	int		cost;
	bool	above_m;
	bool	cheapest;
}	t_stack;

// *** Parsing Functions ***
char	**join_and_split(int ac, char **av);

// *** error handling ***
void	ft_error_exit(int i);
void	ft_free_args(char **split_args);

#endif //PUSH_SWAP_H