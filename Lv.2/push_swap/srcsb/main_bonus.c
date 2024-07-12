/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:30:21 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:31:19 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

char	*standard_input(void);
int		operate(t_num *a, t_num *b, char *structions);

void	ft_checker(t_num *a, t_num *b)
{
	char	*instructions;
	int		sorted;
	int		ope;

	instructions = standard_input();
	ope = operate(a, b, instructions);
	sorted = is_sorted_a(a);
	if (ope == 1 && sorted == 1)
		ft_putstr("OK");
	else if (sorted == 1 && !*instructions)
		ft_putstr("OK");
	else if (ope == 1 && sorted == 0)
		ft_putstr("KO");
	else
		ft_putstr_error("Error\n");
	free(instructions);
}

int	make_list(int argc, char **argv)
{
	t_num	*a;
	t_num	*b;
	int		*arr;
	int		i;
	long	num;

	a = start_node();
	b = start_node();
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num == 9999999999)
			return (free_node_error(a, b));
		add_node(a, num);
		i ++;
	}
	arr = sorted_arr(a);
	if (arr == NULL)
		return (free_node_error(a, b));
	ft_checker(a, b);
	return (free_node(a, b, arr));
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_putstr_error("Error\n"));
	if (make_list(argc, argv) == 1)
		return (ft_putstr_error("Error\n"));
	return (0);
}
