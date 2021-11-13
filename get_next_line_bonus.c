/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:47:06 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/13 15:22:00 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_i(char *saved)
{
	int i;

	i = 0;
	while (saved[i])
	{
		if (saved[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static int has_new_line(char *saved)
{
	int i;

	i = 0;
	while (saved[i])
	{
		if (saved[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*new;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < len)
		new = (char *)malloc(sizeof(char) * (s_len + 1));
	else
		new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			new[j++] = s[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

static char	*return_line(char **saved)
{
	int	i;
	char 	*line;
	char	*temp;

	if (!*saved || **saved == '\0')
		return (NULL);
	i = find_i(*saved);
	if (has_new_line(*saved))
	{
		line = ft_substr(*saved, 0, i + 1);
		temp = ft_substr(*saved, i + 1, ft_strlen(*saved));
		free (*saved);
		*saved = temp;
		if (**saved != '\0')
			return (line);
	}
	else
		line = ft_strdup(*saved);
	free (*saved);
	*saved = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char *buf;
	static char *saved[OPEN_MAX];
	char *temp;
	int ret;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup("");
		temp = ft_strjoin(saved[fd], buf);
		free (saved[fd]);
		saved[fd] = temp;
		if (ft_strchr(saved[fd], '\n'))
			break;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free (buf);
	return (return_line(&saved[fd]));
}
