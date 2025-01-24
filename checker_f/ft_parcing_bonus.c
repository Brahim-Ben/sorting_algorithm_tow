/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:35:46 by bbenaali          #+#    #+#             */
/*   Updated: 2025/01/23 11:14:27 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	digit(char *c)
{
	int	i;

	i = 0;
	if (chek_new_line(c))
		return (0);
	if ((c[i] == '-' || c[i] == '+') && (c[i + 1] == '-' || c[i + 1] == '+'))
		return (0);
	while (c[i] != '\0' && ((c[i] >= '0' && c[i] <= '9')
			|| ((c[i] == '-' || c[i] == '+') && (c[i - 1] == ' ' || i == 0)
				&& (c[i + 1] >= '0' && c[i + 1] <= '9')) || c[i] == ' '))
		i++;
	if (ft_strlen(c) == i)
		return (1);
	else
		return (0);
}

static int	count_elements(char **argv)
{
	int		i;
	int		c;
	int		x;
	char	**split;

	i = 1;
	c = 0;
	while (argv[i] != NULL)
	{
		x = 0;
		split = ft_split(argv[i], ' ');
		while (split[x] != NULL)
		{
			free(split[x]);
			x++;
			c++;
		}
		free(split);
		i++;
	}
	return (c);
}

static void	fill_array(int *b, char **argv)
{
	int		i;
	int		x;
	char	**split;

	i = 1;
	while (argv[i] != NULL)
	{
		x = 0;
		split = ft_split(argv[i], ' ');
		while (split[x] != NULL)
		{
			*b = ft_atoi(split[x]);
			b++;
			free(split[x]);
			x++;
		}
		free(split);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	c;
	int	*b;

	i = 1;
	c = 0;
	if (argc < 2)
		return (0);
	while (argv[i] != NULL && digit(argv[i]))
		i++;
	if (i != argc)
		return (write(2, "Error\n", 6), 1);
	c = count_elements(argv);
	b = (int *)malloc(sizeof(int) * c);
	if (!b)
		return (1);
	fill_array(b, argv);
	ft_check_double_number(b, c);
	put_in_node(b, c);
	free(b);
	return (0);
}
