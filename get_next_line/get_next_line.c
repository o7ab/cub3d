/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:46:06 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/25 19:38:36 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	static char	*store;

	store = gnl_helper(store, fd);
	if (!store)
	{
		free(store);
		return (NULL);
	}
	res = ft_strdup2(store);
	store = ft_get_after_nl(store);
	return (res);
}

char	*ft_get_after_nl(char *store)
{
	int		i;
	int		j;
	char	*new_store;

	i = 0;
	j = 0;
	if (!store)
		return (NULL);
	while (store[i] != '\n' && store[i])
		i++;
	if (!store[i])
	{
		free (store);
		return (NULL);
	}
	new_store = malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!new_store)
		return (NULL);
	i++;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = 0;
	free(store);
	return (new_store);
}
