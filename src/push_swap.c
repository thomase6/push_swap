/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 07:37:33 by texenber          #+#    #+#             */
/*   Updated: 2025/09/12 10:33:27 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_args;

	b = NULL;
	a = NULL;
	if (ac < 2 || ac == 2 && !av[1][0])
		return (1);
	else if (ac > 1)
	{
		split_args = join_and_split(ac, av);
	}
	return (0);
}

/*
-declare pointers to two data structures/linked lists, one for stack 'a' and another for stack 'b'
	-set both pointers to NULL to avoid undefined behavior and indicate we're starting with empty stacks
-Handle input count errors. Argument count must be 2 or more, and the second input myst not be empty.
	-If input errors, return "error\n"
-Handle both cases of input, wether a variable number of command line arguments, or as a string
	-if the input numbers is a string, call ft_split() to split the substrings
- Initialize stack 'a' by appending each input number as a node to stack 'a'
	-handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or '-' '+' signs
		-if errors found, free stack 'a' and return error
	-check for each input, if it is a long integer
		- if the input is a string, convert it to a long integer.
	-append the nodes to stack 'a'
-check if stack 'a' is sorted
	- if not sorted, implement our sorting algorithm
		-check for 2 numbers
			-if so, simply swap the numbers
		-check for 3 numbers
			-if so, implement our simple 'sort three' algorithm
		-check if the stack has more than 3 numbers 
			-if so, implement our turk algorithm
*/