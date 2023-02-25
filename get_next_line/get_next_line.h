/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:38 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/25 19:40:46 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 1000

char	*get_next_line(int fd);
char	*ft_strdup2(char *s1);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*gnl_helper(char *store, int fd);
char	*ft_get_after_nl(char *store);

#endif