#include "ft_ls.h"

static void	ft_callpaths(t_paths **lst, char *flags)
{
	t_paths		*temp;

	temp = (*lst);
	if ((*lst) != NULL)
	{
		ft_sortpath(&(*lst), flags);
		if (temp->next == NULL)
			ft_impliment(temp->path, flags);
		else
			while (temp != NULL)
			{
				ft_putstr(temp->path);
				ft_putendl(":");
				ft_impliment(temp->path, flags);
				temp = temp->next;
			}
	}
	ft_del_p(lst);
}

static void	ft_paths(int ac, char **av, char *flags)
{
	int		i;
	t_long	*lst;
	t_paths	*plst;

	i = 1;
	lst = NULL;
	plst = NULL;
	ft_putendl("hey");
	while (av[i] != NULL && av[i][0] == '-' && ac > i)
		i++;		
	while (av[i] != NULL)
	{
		if (!(opendir(av[i])))
		{
			ft_err(&lst, av[i]);
		}
		else
			if (plst == NULL)
				plst = ft_newpath(av[i]);
			else
				ft_addpath(&plst, ft_newpath(av[i]));
		i++;
	}
	if (lst != NULL)
		ft_callnames(&lst, flags);
	if (plst != NULL)
		ft_callpaths(&plst, flags);
}

int			main(int ac, char **av)
{
	char	*flags;
	int		i;
	char	wrongchar;

	i = 1;
	wrongchar = '\0';
	flags = ft_checkflag(ac, av, &wrongchar);
	if (wrongchar != '\0')
	{
		ft_putstr("ft_ls: invalid option -- '");
		ft_putchar(wrongchar);
		ft_putendl("'\nTry 'ft_ls --help' for more information.");
		return (1);
	}
	while (av[i] != NULL && av[i][0] == '-' && ac > i)
		i++;
	if (av[i] == NULL)
		ft_impliment(".", flags);
	else
		ft_paths(ac, av, flags);
	return (0);
}
