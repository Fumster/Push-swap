
int count_nbrs(int argc, char **argv)
{
    int s;
    int c;
    int cntr;
    int is_num;

    s = 1;
    c = 0;
    cntr = 0;
    is_num = 0;
    while (s < argc)
    {
        while (argv[s][c])
        {
            if (argv[s][c] >= '0' && argv[s][c] <= '9' && is_num == 0)
                cntr++;
            if (argv[s][c] >= '0' && argv[s][c] <= '9')
                is_num = 1;
            else
                is_num = 0;
            c++;
        }
        s++;
    }
    return (cntr);
}
