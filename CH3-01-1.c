/* binsearch_faster: find x in v[0] <= v[1] <= ... <= v[n-1] */
/* version with only one test inside the loop */
int binsearch_faster(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while(low <= high && x != v[mid])
    {
        if(x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if(x == v[mid])
        return mid; /* found match */
    else
        return -1; /* no match */
}
