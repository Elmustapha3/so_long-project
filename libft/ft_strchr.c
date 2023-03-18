/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:44:43 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/14 22:26:13 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;
	int		len;

	len = ft_strlen((char *)s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
		{
			str = (char *)&s[i];
			return (str);
		}
		i++;
	}
	return (0);
}
