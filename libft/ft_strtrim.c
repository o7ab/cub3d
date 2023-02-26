/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:45:16 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/18 10:19:52 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "limits.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start_index;
	size_t	end_index;

	if (!s1)
		return (NULL);
	start_index = 0;
	end_index = ft_strlen(s1) - 1;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	while (end_index >= start_index && ft_strchr(set, s1[end_index]))
		end_index--;
	str = ft_substr(s1, start_index, (end_index - start_index + 1));
	return (str);
}
