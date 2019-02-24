int bsearchWithoutRecursion(int array[],int low,int high,int target)
{
    while(low<=high)
        {
            int mid=low+(high-low)/2;//还是溢出问题
            if(array[mid]>target)
                high=mid-1;
            else if(array[mid]<target)
            low=mid+1;
            else
                return mid;
        }
    return-1;
}