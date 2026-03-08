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