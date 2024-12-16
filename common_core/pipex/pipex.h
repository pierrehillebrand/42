/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:01:42 by phillebr          #+#    #+#             */
/*   Updated: 2024/10/02 12:03:14 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <wait.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(const char *str, char c);
int		clean_path(char **paths, char *str, int test);
int		ft_putstr(char *str);
char	*ft_strjoin(char *s1, char *s2, char separateur);
int		ft_strlen(char *str);
void	*ft_calloc(size_t size, size_t nbr);
void	close_fd(int *files, int ac, int *pid);
void	child(char *path[], char *av[], int *files, int i);

#endif