/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:47:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/12 18:52:23 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char buf[BUFFR_SIZE + 1];
	static char *saved[1024];
	char *line;
	char *temp;
	int ret;

	if ((read(fd, 0, 0) == -1) || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret + 1] = '\0';
	line = until_line(buf, \n);
	saved[fd] = ft_memmove(buf, "\n");
	temp = ft_strjoin(saved[fd], buf);


