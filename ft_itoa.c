/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:57:26 by ncastell          #+#    #+#             */
/*   Updated: 2022/12/30 16:07:51 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizeint(long int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_negatives(long int n)
{
	int		i;
	char	*str;

	n = n * -1;
	i = ft_sizeint(n) + 1;
	str = (char *)(malloc(sizeof(char) * i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
		n = n * -1;
	while (--i > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	str[i] = '-';
	return (str);
}

char	*ft_positives(long int n)
{
	int		i;
	char	*str;

	i = ft_sizeint(n);
	str = (char *)(malloc(sizeof(char) * i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;

	num = n;
	str = NULL;
	if (num < 0)
		str = ft_negatives(num);
	else if (num >= 0)
		str = ft_positives(num);
	return (str);
}
