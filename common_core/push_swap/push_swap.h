/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:57:21 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 15:12:06 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

void	ft_add_back(t_list *first, t_list *new);
void	ft_add_front(t_list *first, t_list *new);
void	ft_list_clean(t_list *first);
t_list	*create(int *int_dest, int size);
void	rotate(t_list **top, t_list **top_optionnel, int type);
void	reverse_rotate(t_list **top, t_list **top_optionnel, int type);
void	switch_list(t_list **top, t_list **top_optionnel, int type);
void	push(t_list **top_a, t_list **top_b, int type);
void	process(t_list **pile_a, t_list **pile_b, int distance, int meilleur);
void	rotate_finish(t_list **pile_a);

int		max_dist(int distance, int meilleur);
int		*convert_int(char *str);
int		count(char *str);
int		*entry_check(int argc, char *argv[], int *size);
int		abs(int x);
int		abs_min(int a, int b);
int		ft_strlen(char *str);
int		check_sorted(int *tab, int size);
void	test_best(int *util, int *distance, int *meilleur, int size_b);
void	ft_putstr(char *str);
void	ft_clean_exit(void *str);
void	*ft_calloc(size_t nbr, size_t size);
void	start(int size, t_list **top_a, t_list **top_b);

#endif
