/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paijavai <paijavai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:38:25 by paijavai          #+#    #+#             */
/*   Updated: 2021/11/01 00:18:04 by paijavai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int nb_lines (char *str)
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

static char *line_ct (char *str)
{
    int i;
    //int j;
    int len;
    char *line;

    len = ft_strlen(str);
    line = malloc(sizeof(char) * (len + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (line[i] == '\n')
	    line[i] = '\n';
    i++;
    line[i] = '\0';
    return (line);
}

int main ()
{
    char str [] = "ola tudo bem \n1 quebra \n2 quebra";
    
    printf("%d\n", nb_lines(str));
    printf("%s", line_ct(str));
    }
