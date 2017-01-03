template <typename T>
int compare(const T &a, const T &b)
{
    if (a < b)
        return -1;
    if (b < a)
        return 1;
    return 0;
}