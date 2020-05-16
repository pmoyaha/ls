#include "ft_ls.h"

t_long	*ft_newnames(char *path, struct dirent *fname)
{
	t_long		*temp;
	struct stat	buff;
	char		*p;

	p = ft_joint(path, "/", fname->d_name);
	lstat(p, &buff);
	if (!(temp = malloc(sizeof(t_long))))
		return (NULL);
	temp->next = NULL;
	temp->filename = fname->d_name;
	temp->time = buff.st_mtime;
	temp->type = ft_type(buff);
	free(p);
	return (temp);
}
