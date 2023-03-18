/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:56:01 by eej-jama          #+#    #+#             */
/*   Updated: 2022/10/29 14:44:47 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*d;

	d = NULL;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			d = ((char *)&s[i]);
		i++;
	}
	return (d);
}
// int main(int argc, char const *argv[])
// {
// 	char *a = NULL;

// 	printf("%s",strrchr(a,'k'));

// 	return 0;
// }
