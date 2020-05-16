#include "ft_ls.h"

char	ft_type(struct stat buff)
{
	if (S_ISREG(buff.st_mode))
		return ('-');
	else if (S_ISLNK(buff.st_mode))
		return ('l');
	else if (S_ISBLK(buff.st_mode))
		return ('b');
	else if (S_ISCHR(buff.st_mode))
		return ('c');
	else if (S_ISSOCK(buff.st_mode))
		return ('s');
	else if (S_ISFIFO(buff.st_mode))
		return ('p');
	else if (S_ISDIR(buff.st_mode))
		return ('d');
	return ('-');
}
