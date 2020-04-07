/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:06:08 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/08 01:18:59 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <stdlib.h>

int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isnumber(int c);
int		ft_isblank(int c);
char	*ft_strpush(char *s, int push);

char	*ft_strndup(const char *s1, size_t n);
char	*ft_strnul(void);

#endif
