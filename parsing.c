#include"push_swap.h"
void ps_free_tokens(char **tokens)
{ 
    int i;
    i=0;
    if (!tokens)
        return ;
    while(tokens[i])
    {  
    free(tokens[i]);
    i++;
    }
    free(tokens);
}

static int	ps_count_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
		j++;
	return (j);
}

int	ps_count_tokens(int argc, char **argv)
{
	int		i;
	int		total;
	char	**split;

	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			ps_free_tokens(split);
			return (-1);
		}
		total += ps_count_split(split);
		ps_free_tokens(split);
		i++;
	}
	return (total);
}


static void	ps_free_partial(char **tokens, int count)
{
	int	i;

	if (!tokens)
		return;
	i = 0;
	while (i < count)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	ps_fill_tokens(char **tokens, char **split, int k)
{
	int	j;

	j = 0;
	while (split[j])
	{
		tokens[k] = ft_strdup(split[j]);
		if (!tokens[k])
			return (-1);
		k++;
		j++;
	}
	return (k);
}

static int	ps_process_arg(char **tokens, char *arg, int k)
{
	char	**split;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
	{
		ps_free_tokens(split);
		return (-1);
	}
	k = ps_fill_tokens(tokens, split, k);
	ps_free_tokens(split);
	return (k);
}

char	**ps_tokenize(int argc, char **argv)
{
	int		total;
	char	**tokens;
	int		i;
	int		k;

	total = ps_count_tokens(argc, argv);
	if (total == -1)
		return (ft_putendl_fd("Error", 2), NULL);
	tokens = malloc((total + 1) * sizeof(char *));
	if (!tokens)
		return (ft_putendl_fd("Error", 2), NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		k = ps_process_arg(tokens, argv[i], k);
		if (k == -1)
			return (ps_free_partial(tokens, 0), NULL);
		i++;
	}
	tokens[k] = NULL;
	return (tokens);
}

