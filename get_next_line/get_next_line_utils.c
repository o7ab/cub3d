/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:51:27 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/25 19:37:32 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	i = 0;
	j = 0;
	ret = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != 0)
		ret[i++] = s2[j++];
	ret[i] = 0;
	free(s1);
	return (ret);
}

char	*ft_strdup2(char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s1[0])
		return (NULL);
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	i++;
	ptr = malloc((i * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] != '\n' && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*gnl_helper(char *store, int fd)
{
	int		bytes;
	char	str[BUFFER_SIZE + 1];

	bytes = 1;
	while (bytes != 0 && !ft_strchr(store, '\n'))
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		str[bytes] = 0;
		store = ft_strjoin2(store, str);
	}
	return (store);
}
