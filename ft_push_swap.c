/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:10:42 by ael-hana          #+#    #+#             */
/*   Updated: 2016/01/20 18:10:06 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_error()
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_swap		*ft_init_list(int max, int i, char *av, t_swap *next)
{
	t_swap	*ptr;


	if (!(ptr = malloc(sizeof(t_swap))))
		ft_error();
	ptr->next = next;
	ptr->max = max;
	ptr->data = ft_atoi(av);
	ptr->i = i;
	return (ptr);
}

t_swap		*ft_creat_list(int max, char **av)
{
	int		i;
	void	*save;
	t_swap	*ptr;

	i = 2;
	ptr = ft_init_list(max, 1, av[1], NULL);
	save = ptr;
	while (i <= max)
	{
		ptr->next = ft_init_list(max, i, av[i], save);
		ptr = ptr->next;
		++i;
	}
	return (ptr->next ? ptr->next : ptr);
}

void	ft_print_list(t_swap *ptr)
{
	while (ptr->max > ptr->i)
	{
		printf("le max est : %d, le i est %d, la data est %d\n", ptr->max, ptr->i, ptr->data);
		ptr = ptr->next;
	}
	printf("le max est : %d, le i est %d, la data est %d\n", ptr->max, ptr->i, ptr->data);
}

int		main(int ac, char **av)
{
	ft_check_params(ac, av);
	ft_print_list(ft_creat_list(ac - 1, av));
	return (0);
}
