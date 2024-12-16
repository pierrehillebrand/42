/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:41:30 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 15:54:54 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../push_swap_bonus.h"

static void	exit_instruction(t_list **pile_a, t_list **pile_b, char *entry)
{
	ft_list_clean(*pile_a);
	ft_list_clean(*pile_b);
	ft_putstr("Error");
	free(entry);
	exit(-1);
}

static void	instruction(t_list **pile_a, t_list **pile_b, char *entry)
{
	if (!ft_strcmp(entry, "sa\n"))
		switch_list(pile_a, NULL, 3);
	else if (!ft_strcmp(entry, "sb\n"))
		switch_list(pile_b, NULL, 3);
	else if (!ft_strcmp(entry, "ss\n"))
		switch_list(pile_a, pile_b, 4);
	else if (!ft_strcmp(entry, "pa\n"))
		push(pile_b, pile_a, 2);
	else if (!ft_strcmp(entry, "pb\n"))
		push(pile_a, pile_b, 2);
	else if (!ft_strcmp(entry, "ra\n"))
		rotate(pile_a, NULL, 3);
	else if (!ft_strcmp(entry, "rb\n"))
		rotate(pile_b, NULL, 3);
	else if (!ft_strcmp(entry, "rr\n"))
		rotate(pile_a, pile_b, 4);
	else if (!ft_strcmp(entry, "rra\n"))
		reverse_rotate(pile_a, NULL, 3);
	else if (!ft_strcmp(entry, "rrb\n"))
		reverse_rotate(pile_b, NULL, 3);
	else if (!ft_strcmp(entry, "rrr\n"))
		reverse_rotate(pile_a, pile_b, 4);
	else
		exit_instruction(pile_a, pile_b, entry);
}

static void	loop(t_list **pile_a, t_list **pile_b, int test)
{
	char	*entry;

	entry = get_next_line(0);
	if (test)
	{
		if (entry != NULL)
			exit_instruction(pile_a, pile_b, entry);
	}
	while (entry != NULL)
	{
		instruction(pile_a, pile_b, entry);
		free(entry);
		entry = get_next_line(0);
	}
}

static void	check_sorted_pile(t_list **pile_a, t_list **pile_b)
{
	t_list	*memory;
	char	*result;

	result = "OK";
	if (*pile_b)
		result = "KO";
	memory = *pile_a;
	while (memory->next != *pile_a)
	{
		if (memory->value > memory->next->value)
		result = "KO";
		memory = memory->next;
	}
	ft_putstr(result);
}

int	main(int argc, char *argv[])
{
	int		size;
	int		*dest;
	t_list	*pile_a;
	t_list	*pile_b;

	if (argc == 1)
		return (1);
	pile_b = NULL;
	dest = entry_check(argc, argv, &size);
	if (!dest)
		return (0);
	pile_a = create(dest, size);
	if (!check_sorted(dest, size))
	{
		free(dest);
		loop(&pile_a, &pile_b, 1);
	}
	else
	{
		free(dest);
		loop(&pile_a, &pile_b, 0);
		check_sorted_pile(&pile_a, &pile_b);
	}
	ft_list_clean(pile_a);
	ft_list_clean(pile_b);
}
