/*¶þ·Ö*/
int BinS(int arr[], int low, int high, int x)
{
    int mid;
    while(low < high)
    {
        mid = (low+high)/2;
        if(x == arr[mid])   return mid;
        else if(x < arr[mid])   high = mid-1;
        else    low = mid+1;
    }
    return -1;
}
