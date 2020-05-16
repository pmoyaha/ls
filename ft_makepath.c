#include "ft_ls.h"

void	ft_addpath(t_paths **lst, t_paths *nlst)
{
	t_paths	*temp;

	temp = (*lst);
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	(*lst)->next = nlst;
	(*lst) = temp;
}

t_paths	*ft_newpath(char *path)
{
	t_paths		*temp;
	struct stat	buff;

	if (!(temp = malloc(sizeof(t_paths))))
		return (NULL);
	lstat(path, &buff);
	temp->next = NULL;
	temp->path = path;
	temp->time = buff.st_mtime;
	return (temp);
}
