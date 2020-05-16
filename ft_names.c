#include "ft_ls.h"

t_long	*ft_names(char *flags, char *path)
{
	t_long			*temp;
	DIR				*dname;
	struct dirent	*fname;

	temp = NULL;
	if ((dname = opendir(path)) != NULL)
	{
		fname = readdir(dname);
		while (fname != NULL)
		{
			if (fname->d_name[0] == '.' && flags[0] == '0')
				fname = readdir(dname);
			else
			{
				if (temp == NULL)
					temp = ft_newnames(path, fname);
				else
					ft_addnames(&temp, ft_newnames(path, fname));
				fname = readdir(dname);;
			}
		}
		closedir(dname);
		ft_sort(&temp, flags);
	}
	return (temp);
}
