/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:21:30 by ncastell          #+#    #+#             */
/*   Updated: 2022/12/31 01:43:27 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
			i++;
	while (ft_strrchr(set, s1[len]) && len)
		len--;
	return (ft_substr(&s1[i], 0, (len - i) + 1));
}
/*
int	main()
{
	printf("*%s*", ft_strtrim("Hola gente de 42 Barcelona", "42 "));
}*/
