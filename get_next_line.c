/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:38:25 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/01 18:31:30 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char new_line (char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
        {
            return (1);
        }
        i++;
    }
    return (0);
}

static char *line (char *str)
{
    int i;
    int len;
    char *line;

    len = ft_strlen(str);
    line = malloc(sizeof(char) * (len + 1));
    if (!line)
        return (NULL);
    line[len] = '\0';
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
        line[i] = str[i];
    i++;
    line[i] = '\0';
    return (line);
}

// char    *get_next_line(int fd)
// {
//     int i;
//     //int j;
//     char buf[BUFFER_SIZE + 1];

//     if (fd == -1)
//         return (NULL);
//     i = read(fd, buf, BUFFER_SIZE);
//     buf = line()
//     buf[i] = '\0';
    
// }

int main ()
{
    char str [] = "ola tudo bem \n1 quebra \n2 quebra";
    
    printf("%d\n", new_line(str));
    printf("%s", line(str));
    }