#include"push_swap.h"
int	*ps_parse_numbers(int argc, char **argv)
{
	char	**tokens;
	int		*numbers;
	int		count;

	tokens = ps_tokenize(argc, argv);
	if (!tokens)
		return (NULL);
	count = ps_tokens_len(tokens);
	numbers = ps_tokens_to_numbers(tokens);
	ps_free_tokens(tokens);
	if (!numbers)
		return (NULL);
	if (ps_has_duplicate(numbers, count))
	{
		free(numbers);
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	return (numbers);
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