/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:38:25 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/06 19:56:20 by bmiguel-         ###   ########.fr       */
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
            return(1);
        }
        i++;
    }
    return (0);
}

static char *get_line (char *str)
{
    int i;
    char len;
    char *line;
    char *storage;
   
    len = 30;
    line = malloc(sizeof(char) * (len + 1));
    storage = NULL;
    if (!line)
        return (NULL);
    i = 0;
    while (*str && i < len)
    {
        line[i++] = *str++;
        i++;
    }
    line[i] = '\0';
    while (*str)
    {
        *storage++ = *str++;
    }
    printf("%s\n", storage);
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
    char str [] = "ola todo bem \n1 quebra \n2 quebra";
    
    printf("%d\n", new_line(str));
    printf("%s\n", get_line(str));
    
    }
