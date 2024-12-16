/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:42:51 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 15:13:37 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 1
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_dup2(char *str, size_t size);
char		*dupfinal(char *str);
char		*get_next_line(int fd);
long long	ft_strrchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);

#endif
