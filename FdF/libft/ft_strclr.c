/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:03:13 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 20:03:14 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int i;
	int j;

	if (s == '\0')
		return ;
	j = -1;
	i = -1;
	while (s[++i])
		;
	while (++j < i)
		s[j] = 0;
}
