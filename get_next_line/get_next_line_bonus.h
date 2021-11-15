/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:31:47 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/15 21:42:03 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

# define OPEN_MAX 256

#endif
