/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <eej-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:54:59 by eej-jama          #+#    #+#             */
/*   Updated: 2022/10/22 17:31:43 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	f(unsigned int a, char *b)
{
     *b = 'a';
}
int	main(void)
{
	char	a[];

    a[] = "ahmed";
    ft_striteri(a ,f);
    printf("%s",a);
}
*/
