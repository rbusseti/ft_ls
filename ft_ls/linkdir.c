#include "ft_ls.h"

void	ft_blank_spaces(int size, int print)
{
    int		n_size;
    int		n_print;

    n_size = 0;
    n_print = 0;
    while (size > 9)
    {
	n_size++;
	size = size / 10;
    }
    while (print > 9)
    {
	n_print++;
	print = print / 10;
    }
    while (n_size > n_print)
    {
	ft_putchar(' ');
	n_print++;
    }
}

void	ft_linkdir(t_file *file, int size)
{
    int		n_rep;

    if (file->stat->st_mode & S_IFDIR)
    {
	n_rep = ft_get_dir_nbr(file);
	ft_blank_spaces(size, n_rep);
	ft_putnbr(n_rep);
    }
    else
    {
	ft_blank_spaces(size, file->stat->st_nlink);
	ft_putnbr(file->stat->st_nlink);
    }
    ft_putchar(' ');
}
