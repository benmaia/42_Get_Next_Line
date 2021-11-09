/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:04:27 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/09 14:58:21 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_line_break(char *save)
{
	int			i;
	char		*ret;

	i = 0;
	ret = ft_strdup(save);
	while (ret[i] != '\n')
		i++;
	ret[i + 1] = '\0';
	return (ret);
}

char	*ft_return_line(char **save)
{
	char		*ret;
	char		*temp;
	int			n;

	if (!*save || **save == '\0')
		return (NULL);
	n = (int)((ft_strchr(*save, '\n')) - ft_strlen(*save));
	if (ft_strchr(*save, '\n'))
	{
		ret = ft_substr(*save, 0, n + 1);
		temp = ft_substr(*save, n + 1, ft_strlen(*save));
		free (*save);
		*save = temp;
		if (**save != '\0')
			return (ret);
	}
	else
		ret = ft_strdup(*save);
	free (*save);
	*save = NULL;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*temp;
	char		*buffer;
	static char	*save[1024];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	buffer = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup("");
		temp = ft_strjoin(save[fd], buffer);
		free (save[fd]);
		save[fd] = temp;
		if (ft_strchr(save[fd], '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free (buffer);
	return (ft_return_line(&save[fd]));
}