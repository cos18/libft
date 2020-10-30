/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 23:33:54 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/30 20:39:55 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** desc : push string by given push integer
** params : char pointer and push integer
** returns : origin char pointer
** ex) ft_strpush("hello", 2) => return "llo"
*/

char	*ft_strpush(char *s, int push)
{
	int	locate;

	locate = 0;
	while (s[locate + push])
	{
		s[locate] = s[locate + push];
		locate++;
	}
	while (s[locate])
		s[locate++] = '\0';
	return (s);
}
