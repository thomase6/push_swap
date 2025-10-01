/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:07:58 by texenber          #+#    #+#             */
/*   Updated: 2025/10/01 09:22:49 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	too_many_0(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] == '0')
		i++;
	if (ft_strlen(&str[i]) > 11)
		return (false);
	return (true);
}

static char	*ps_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_calloc((len1 + len2 + 2), (sizeof(char)));
	if (!join)
		return (NULL);
	while (s1[i])
		join[j++] = s1[i++];
	if (j != 0)
		join[j++] = ' ';
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	return (join);
}

static char	*join_all_args(int ac, char **av)
{
	int		i;
	char	*join;
	char	*tmp;

	i = 1;
	join = ft_strdup("");
	if (!join)
		return (NULL);
	while (i < ac)
	{
		tmp = ps_strjoin(join, av[i]);
		free(join);
		if (!tmp)
			return (NULL);
		join = tmp;
		i++;
	}
	return (join);
}

char	**join_and_split(int ac, char **av)
{
	char	*tmp;
	char	**split_args;

	tmp = join_all_args(ac, av);
	split_args = ft_split (tmp, ' ');
	free (tmp);
	if (!split_args)
		return (NULL);
	return (split_args);
}
