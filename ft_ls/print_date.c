#include "ft_ls.h"

void	ft_print_date(t_stat *stat)
{
    char	**date;
    int		i;

    date = ft_strsplit(ctime(&(stat->st_mtime)), ' ');
    i = 0;
    ft_putstr(date[1]);
    ft_putchar(' ');
    ft_putstr(date[2]);
    ft_putchar(' ');
    while (date[3][i] && i < 5)
    {
	ft_putchar(date[3][i]);
	i++;
    }
    ft_putchar(' ');
}
