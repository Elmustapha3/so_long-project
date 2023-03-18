/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:06:40 by eej-jama          #+#    #+#             */
/*   Updated: 2022/10/30 10:16:45 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}
// int main()
// {
// 	char *p = calloc(1111111111114752,1);
// 	// for(int i = 0; i < 6;i++)
// 	// {
// 	// 	printf("%d\t",p[i]);
// 	// }
// 	//printf("%zu",SIZE_MAX);
// 	//puts(p);
// }
