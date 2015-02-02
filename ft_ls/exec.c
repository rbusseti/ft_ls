#include "ft_ls.h"

void	    ft_exec_ls(t_data *data, int line, char *aff_dir, char *path)
{
    int		*options;

    options = data->options;
//    if (!O_HIDDEN)
//	ft_clean_list(&(data->targets), data->options);
    if (O_TIME)
	ft_time_sort(&(data->targets));
    else
	ft_alph_sort(&(data->targets));
    if (O_REVERSE)
	ft_rev_sort(&(data->targets));
    ft_aff_ls(&(data->targets), line, aff_dir, data->options);
    line = 1;
    if (O_RECURSIVE)
	ft_rec_ls(data, line, aff_dir, path);
}
