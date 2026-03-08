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

    int	ps_count_tokens(int argc, char **argv)
{
	int		i;
	int		j;
	int		total;
	char	**split;

	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		if (split[0] == NULL)
		{
			ps_free_tokens(split);
			return (-1);
		}
		j = 0;
		while (split[j])
		{
			total++;
			j++;
		}
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

char	**ps_tokenize(int argc, char **argv)
{
	int		total;
	char	**tokens;
	int		i;
	int		k;
	char	**split;

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
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			return (ps_free_tokens(split), ps_free_partial(tokens, k), NULL);
		k = ps_fill_tokens(tokens, split, k);
		ps_free_tokens(split);
		if (k == -1)
			return (ps_free_partial(tokens, 0), NULL);
		i++;
	}
	tokens[k] = NULL;
	return (tokens);
}
int	check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}
