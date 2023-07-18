/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:32:12 by ncastell          #+#    #+#             */
/*   Updated: 2022/11/28 14:47:20 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)(malloc(sizeof(char) * (ft_strlen((char *)s1) + 1)));
	if (!str)
		return (NULL);
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	str[i] = '\0';
	return (str);
}
