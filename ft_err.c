#include "ft_ls.h"

void	ft_err(t_long **lst, char *path)
{
	t_long			*temp;
	t_long			*nlst;
	struct stat		buff;

	nlst = NULL;
	if (errno == 2)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putendl(": No such file or directory");
		exit(0);
	}
	else if (errno == 13)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putendl(": Permission denied");
		exit(0);
	}
	if (errno == 20)
	{
		lstat(path, &buff);
		if ((*lst) == NULL)
		{
			if (!((*lst) = malloc(sizeof(t_long))))
				return ;
			(*lst)->next = NULL;
			nlst->filename = ft_strrchr(path, '/');
			(*lst)->time = buff.st_mtime;
			(*lst)->type = ft_type(buff);
			ft_putendl(nlst->filename);
		}
		else
		{
			if (!(nlst = malloc(sizeof(t_long))))
				return ;
			nlst->next = NULL;
			nlst->filename = ft_strrchr(path, '/');
			nlst->time = buff.st_mtime;
			nlst->type = ft_type(buff);
			temp = *lst;
			while ((*lst)->next != NULL)
				*lst = (*lst)->next;
			(*lst)->next = nlst;
			*lst = temp;
		}
	}
}
