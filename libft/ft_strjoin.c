/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:37 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/01 22:22:20 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s, const char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;
	char	*s1;

	s1 = (char *)s;
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (i < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
