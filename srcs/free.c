/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:57:00 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/06 11:57:11 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

t_point	**ft_tab_free(t_point **s, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free((void *)s[j]);
		s[j] = NULL;
		j += 1;
	}
	free(s);
	return (0);
}

char	**ft_tab_free_char(char **s)
{
	int	j;

	j = 0;
	while (s[j] != NULL)
	{
		if (s[j])
		{
			free(s[j]);
			s[j] = NULL;
		}
		j += 1;
	}
	free(s);
	return (0);
}
