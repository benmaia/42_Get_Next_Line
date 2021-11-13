/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:47:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/13 12:24:01 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*has_nline(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == \n)
			return (1);
		i++;
	}
	return (0);
}

char	*until_line(char *buf)
{
	char *line;
	int i;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char buf[BUFFR_SIZE + 1];
	static char *saved[OPEN_MAX];
	char *line;
	char *temp;
	int ret;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	if (!buf)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup("");
		temp = ft_strjoin(saved[fd], buf);
		free saved[fd];
		saved[fd] = temp;
		if (ft_strchr(saved[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}




	line = until_line(buf, \n);
	saved[fd] = ft_memmove(buf, "\n");
	temp = ft_strjoin(saved[fd], buf);
}

