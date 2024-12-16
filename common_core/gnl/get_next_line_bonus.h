/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:56:47 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/24 15:44:59 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# define MAX_FD 8192
# define B BUFFER_SIZE
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

int			ft_strlen(char *str);
char		*ft_calloc(size_t size);
char		*ft_dup2(char *str, size_t size);
char		*dupfinal(char *str);
char		*get_next_line(int fd);
long long	ft_strrchr(const char *s, int c);
void		destructor(void)__attribute__((destructor));

#endif
