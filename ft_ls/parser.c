#include "ft_ls.h"

static void	ft_get_options(char *arg, t_data *data)
{
    int	    i;

    i = 1;
    while (arg[i])
    {
	if (arg[i] == 'l')
	    data->options[0] = 1;
	else if (arg[i] == 'R')
	    data->options[1] = 1;
	else if (arg[i] == 'a')
	    data->options[2] = 1;
	else if (arg[i] == 'r')
	    data->options[3] = 1;
	else if (arg[i] == 't')
	    data->options[4] = 1;
	else
	    ft_putstr("pas bon"); //erreur
	i++;
    }
}

static void	ft_parse_arg(t_data *data, char *arg)
{
    int	    i;

    i = 0;
    if (arg[i] == '-')
	ft_get_options(arg, data);
    else
	ft_list_push_back(&(data->targets), ft_strdup(arg));
}

void		ft_browse_arg(t_data *data, char **argv)
{
    int	    i;

    i = 1;
    while (argv[i])
    {
	ft_parse_arg(data, argv[i]);
	i++;
    }
}
