/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:38:25 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/08 15:01:47 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int got_new_line(char *pocket)
{
    int i;

    if (!pocket)
        return (0);
    i = 0;
    while (pocket[i])
    {
        if (pocket[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *until_line(char *pocket)
{
    int i;
    char *line;

    if (!pocket)
        return (NULL);
    i = 0;
    while (pocket[i] && pocket[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (pocket[i] && pocket[i] != '\n')
    {
        line[i] = pocket[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char *after_line(char *pocket)
{
    int i;
    int j;
    char *new_line;

    if (!pocket)
        return (NULL);
    i = 0;
    while (pocket [i] != '\n' && pocket[i])
        i++;
    new_line = (char *)malloc(sizeof(char) * (ft_strlen(pocket) - i + 1));
    if (!new_line)
        return (NULL);
    i++;
    j = 0;
    while (pocket[i])
        new_line[j++] = pocket[i++];
    new_line[j] = '\0';
    free(pocket);
    return (new_line);
}

char *get_next_line(int fd)
{
    static char *pocket[1024];
    char **line = NULL;
    char *buf;
    int reader;

    if (fd < 0 || (BUFFER_SIZE < 0))
        return (NULL);
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
    reader = 1;
    while (!got_new_line(pocket[fd]) && reader != 0)
    {
        reader = read(fd, buf, BUFFER_SIZE);
        if (reader == -1)
        {
            free(buf);
            return (NULL);
        }
        //buf[reader] = '\0';
        pocket[fd] = ft_strjoin(pocket[fd], (char *)buf);
    }
    free(buf);
    *line = until_line(pocket[fd]);
    pocket[fd] = after_line(pocket[fd]);
    return (*line);
}