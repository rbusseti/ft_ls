#include "ft_ls.h"

int	ft_check_hidden(char *str)
{
    int         i;

    i = ft_strlen(str);
    while (str[i] != '/' && i > 0)
        i--;
    if (i != 0)
        i++;
    if (str[i] == '.')
        return (1);
    else
        return (0);
}
