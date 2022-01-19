/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:55:28 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/06 11:57:50 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

long	set_res(char *nbr, char *base_from, int res, int j)
{
	if (base_from[j] >= 'a' && base_from[j] < 'z')
	{
		if (*nbr == base_from[j] || *nbr == base_from[j] - 32)
			res = ft_strlen(base_from) * res + j;
	}
	else if (base_from[j] >= 'A' && base_from[j] < 'Z')
	{
		if (*nbr == base_from[j] || *nbr == base_from[j] + 32)
			res = ft_strlen(base_from) * res + j;
	}
	else if (*nbr == base_from[j])
		res = ft_strlen(base_from) * res + j;
	return (res);
}

long	ft_atoi_base(char *nbr, char *base_from)
{
	long	res;
	int		j;
	int		k;
	int		neg;

	neg = 1;
	res = 0;
	k = 0;
	if (*nbr == '-')
	{
		neg = -1;
		nbr++;
	}
	while (*nbr && *nbr != ' ')
	{
		j = -1;
		while (base_from[++j])
			res = set_res(nbr, base_from, res, j);
		nbr++;
		k++;
	}
	return (res * neg);
}
