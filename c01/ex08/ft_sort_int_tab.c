/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:31:44 by gtoubol           #+#    #+#             */
/*   Updated: 2022/10/06 19:32:49 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NEXT (void *)0

typedef struct s_node
{
	struct s_node	*next;
	int				content;
}	t_node;

static int	ft_random(t_node *root)
{
	int	_down_;
	int	_up_;

	_down_ = root->content;
	_up_ = root->content;
	while (root != NEXT)
	{
		if (root->content < _down_)
			_down_ = root->content;
		if (root->content > _up_)
			_up_ = root->content;
		root = root->next;
	}
	return ((_down_ + _up_) / 2);
}

static void	ft_add_last(t_node **root, t_node *node)
{
	t_node	*tmp;

	if (*root == NEXT)
	{
		*root = node;
		return ;
	}
	tmp = *root;
	while (tmp->next != NEXT)
		tmp = tmp->next;
	tmp->next = node;
}

static void	ft_magicsort(t_node **root)
{
	t_node	*left;
	t_node	*right;
	t_node	*tmp;
	int		i;

	left = NEXT;
	right = NEXT;
	if (*root == NEXT || (*root)->next == NEXT)
		return ;
	i = ft_random(*root);
	while (*root != NEXT)
	{
		tmp = (*root)->next;
		(*root)->next = NEXT;
		if ((*root)->content <= i)
			ft_add_last(&left, *root);
		else
			ft_add_last(&right, *root);
		*root = tmp;
	}
	ft_magicsort(&left);
	ft_magicsort(&right);
	ft_add_last(&left, right);
	*root = left;
}

static void	ft_nodify(t_node *node, int *tab, int size, int *tab0)
{
	t_node	next_node;
	int		i;

	if (size == 0)
	{
		ft_magicsort(&node);
		i = 0;
		while (node != NEXT)
		{
			tab0[i] = node->content;
			node = node->next;
			++i;
		}
		return ;
	}
	next_node = (t_node){NEXT, *tab};
	ft_add_last(&node, &next_node);
	ft_nodify(node, ++tab, --size, tab0);
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_nodify(NEXT, tab, size, tab);
}

/*
#include <stdio.h>

int	main(void)
{
	int	tab[7] = {0, 2, 6, 1, 4, 3, 5};
	int	i;

	i = 0;
	ft_sort_int_tab(tab, 7);
	while (i < 7)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		++i;
	}
	return (0);
}
*/
