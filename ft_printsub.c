#include "ft_ls.h"

void	ft_printsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s || !(str = ft_strnew(len)))
		return ;
	ft_memset(str, '\0', len);
	ft_strncpy(str, s + start, len);
	ft_putstr(str);
	free(str);
}
