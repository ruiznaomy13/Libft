/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:09:15 by ncastell          #+#    #+#             */
/*   Updated: 2022/10/25 11:32:02 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1 [i + j] == s2[j] && i + j < n)
			{
				j++;
				if (!s2[j])
					return ((char *)&s1[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
int	main()
{
	char s1[50] = "Hola gente guapa de todo el mundo entero.";
	char s2[20] = "gente";

	printf("s1 = %s s2 = %s\n  %s\n\n", s1, s2, strnstr(s1,s2,20));
	printf("s1 = %s s2 = %s\n %s", s1, s2, ft_strnstr(s1, s2, 20));

	return 0;
}*/
