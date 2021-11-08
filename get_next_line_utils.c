/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiguel- <bmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:31:43 by bmiguel-          #+#    #+#             */
/*   Updated: 2021/11/08 12:21:46 by bmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    char *new;
    int i;


    new = (char *)malloc(sizeof(char) * (ft_strlen(str)+ 1));
    if (!new)
        return (NULL);
    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *ft_strjoin(char *str1, char *str2)
{
    size_t i;
    size_t j;
    size_t len;
    char *cat;
    
    if (!str1 && !str2)
        return (NULL);
    if (!str1)
        return (ft_strdup(str2));
    len = (ft_strlen(str1) + ft_strlen(str2) + 1);
    cat = (char *)malloc(sizeof(char) * len);
    if (!cat)
        return (NULL);
    i = -1;
    while (str1[++i])
        cat[i] = str1[i];
    j = -1;
    while (str2[++j])
    {
        cat[i + j] = str2[j];
    }
    cat[i + j] = '\0';
    free (str1);
    return (cat);
}