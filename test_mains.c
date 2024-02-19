//+++++++++test high / low / sorted++++++++++++++++

// int	main(int ac, char *av[])
// {
// 	int	i;

// 	i = 1;
// 	t_list *root = NULL;
// 	while (ac > i)
// 	{
// 		t_list *stack_a = malloc(sizeof(t_list));
// 		if (!stack_a)
// 			return (0);
// 		stack_a->content = ft_atol(av[i]);
// 		stack_a->next = NULL;
// 		ft_lstadd_back(&root, stack_a);
// 		i++;
// 	}
//     printf("%s\n", "before sorting:");
//     //t_list *current = root;
//     // while (current != NULL)
//     // {
//     //     printf("%ld\n", current->content);
//     //     current = current->next;
//     // }
//     printf("%s\n", "is sorted:");
//     //printf("%d\n", is_sorted(root));
// 		// printf("%s\n", "is highest:");	/////testing highest////
//     	// t_list *current = highest(root);
//         // printf("%ld\n", current->content);
// 	printf("%s\n", "is lowest:");	/////testing lowest////
//     t_list *current = lowest(root);
//     printf("%ld\n", current->content);
//     return (0);
// }

//+++++++++push++++++++++++++++
/*
int	main(void)
{
    int i;
    int j;
    i = 0;
    j = 5;
    
    t_list *root_a = NULL;
    t_list *root_b = NULL;
    
    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root_a, stack_a);
		i++;
    }
    while (j < 10)
	{
        t_list *stack_b = malloc(sizeof(t_list));
		if (!stack_b)
			return (0);
		stack_b->content = j;
        stack_b->next = NULL;
		ft_lstadd_back(&root_b, stack_b);
		j++;
    }
    printf("%s\n", "before push a:");
    t_list *current_a = root_a;
    while (current_a != NULL)
    {
        printf("%ld\n", current_a->content);
        current_a = current_a->next;
    }
    printf("%s\n", "before push b:");
    t_list *current_b = root_b;
    while (current_b != NULL)
    {
        printf("%ld\n", current_b->content);
        current_b = current_b->next;
    }
    printf("%s\n", "after push a:");
    push_b(&root_a, &root_b);
    t_list *current_a2 = root_a;
    while (current_a2 != NULL)
    {
        printf("%ld\n", current_a2->content);
        current_a2 = current_a2->next;
    }
    printf("%s\n", "after push b:");
    t_list *current_b2 = root_b;
    while (current_b2 != NULL)
    {
        printf("%ld\n", current_b2->content);
        current_b2 = current_b2->next;
    }
    return (0);
}
*/

//+++++++++rev_rotate++++++++++++++++

/*
int	main(void)
{
    int i;
    int j;
    i = 0;
    j = 5;

    t_list *root_a = NULL;
    t_list *root_b = NULL;

    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root_a, stack_a);
		i++;
    }
    while (j < 10)
	{
        t_list *stack_b = malloc(sizeof(t_list));
		if (!stack_b)
			return (0);
		stack_b->content = j;
        stack_b->next = NULL;
		ft_lstadd_back(&root_b, stack_b);
		j++;
    }
    printf("%s\n", "before swap_ab a:");
    t_list *current_a = root_a;
    while (current_a != NULL)
    {
        printf("%ld\n", current_a->content);
        current_a = current_a->next;
    }
    printf("%s\n", "before swap_ab b:");
    t_list *current_b = root_b;
    while (current_b != NULL)
    {
        printf("%ld\n", current_b->content);
        current_b = current_b->next;
    }
    printf("%s\n", "after swap_ab a:");
    rev_rotate_ab(&root_a, &root_b);
    t_list *current_a2 = root_a;
    while (current_a2 != NULL)
    {
        printf("%ld\n", current_a2->content);
        current_a2 = current_a2->next;
    }
    printf("%s\n", "after swap_ab b:");
    //swap_ab(&root_a, &root_b);
    t_list *current_b2 = root_b;
    while (current_b2 != NULL)
    {
        printf("%ld\n", current_b2->content);
        current_b2 = current_b2->next;
    }
    return (0);
}
*/


/*
int	main(void)
{
    int i;
    i = 1;
    t_list *root = NULL;
    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root, stack_a);
		i++;
    }
    printf("%s\n", "before rotate_a:");
    t_list *current = root;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
    printf("%s\n", "after rotate_a:");
    rev_rotate_b(&root);
    t_list *current2 = root;
    while (current2 != NULL)
    {
        printf("%ld\n", current2->content);
        current2 = current2->next;
    }
    return (0);
}
*/

//+++++++++rotate++++++++++++++++

//for testing double commands
/*
int	main(void)
{
    int i;
    int j;
    i = 0;
    j = 5;
    
    t_list *root_a = NULL;
    t_list *root_b = NULL;
    
    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root_a, stack_a);
		i++;
    }
    while (j < 10)
	{
        t_list *stack_b = malloc(sizeof(t_list));
		if (!stack_b)
			return (0);
		stack_b->content = j;
        stack_b->next = NULL;
		ft_lstadd_back(&root_b, stack_b);
		j++;
    }
    printf("%s\n", "before swap_ab a:");
    t_list *current_a = root_a;
    while (current_a != NULL)
    {
        printf("%ld\n", current_a->content);
        current_a = current_a->next;
    }
    printf("%s\n", "before swap_ab b:");
    t_list *current_b = root_b;
    while (current_b != NULL)
    {
        printf("%ld\n", current_b->content);
        current_b = current_b->next;
    }
    printf("%s\n", "after swap_ab a:");
    rotate_ab(&root_a, &root_b);
    t_list *current_a2 = root_a;
    while (current_a2 != NULL)
    {
        printf("%ld\n", current_a2->content);
        current_a2 = current_a2->next;
    }
    printf("%s\n", "after swap_ab b:");
    t_list *current_b2 = root_b;
    while (current_b2 != NULL)
    {
        printf("%ld\n", current_b2->content);
        current_b2 = current_b2->next;
    }
    return (0);
}


//for testing single commands


int	main(void)
{
    int i;
    i = 1;
    t_list *root = NULL;
    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root, stack_a);
		i++;
    }
    printf("%s\n", "before rotate_a:");
    t_list *current = root;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
    printf("%s\n", "after rotate_a:");
    rotate_a(&root);
    t_list *current2 = root;
    while (current2 != NULL)
    {
        printf("%ld\n", current2->content);
        current2 = current2->next;
    }
    return (0);
}
*/

//+++++++++swap++++++++++++++++
/*
int	main(void)
{
    int i;
    int j;
    i = 0;
    j = 5;
    
    t_list *root_a = NULL;
    t_list *root_b = NULL;
    
    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root_a, stack_a);
		i++;
    }
    while (j < 10)
	{
        t_list *stack_b = malloc(sizeof(t_list));
		if (!stack_b)
			return (0);
		stack_b->content = j;
        stack_b->next = NULL;
		ft_lstadd_back(&root_b, stack_b);
		j++;
    }
    printf("%s\n", "before swap_ab a:");
    t_list *current_a = root_a;
    while (current_a != NULL)
    {
        printf("%ld\n", current_a->content);
        current_a = current_a->next;
    }
    printf("%s\n", "before swap_ab b:");
    t_list *current_b = root_b;
    while (current_b != NULL)
    {
        printf("%ld\n", current_b->content);
        current_b = current_b->next;
    }
    printf("%s\n", "after swap_ab a:");
    swap_ab(&root_a, &root_b);
    t_list *current_a2 = root_a;
    while (current_a2 != NULL)
    {
        printf("%ld\n", current_a2->content);
        current_a2 = current_a2->next;
    }
    printf("%s\n", "after swap_ab b:");
    //swap_ab(&root_a, &root_b);
    t_list *current_b2 = root_b;
    while (current_b2 != NULL)
    {
        printf("%ld\n", current_b2->content);
        current_b2 = current_b2->next;
    }
    return (0);
}


int	main(void)
{
    int i;
    i = 1;
    
    t_list *root = NULL;
    while (i < 5)
	{
        t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
        stack_a->next = NULL;
		ft_lstadd_back(&root, stack_a);
		i++;
    }
    printf("%s\n", "before swap_a:");
    t_list *current = root;
    while (current != NULL)
    {
        printf("%ld\n", current->content);
        current = current->next;
    }
    printf("%s\n", "after swap_a:");
    swap_a(&root);
    t_list *current2 = root;
    while (current2 != NULL)
    {
        printf("%ld\n", current2->content);
        current2 = current2->next;
    }
    return (0);
}
*/