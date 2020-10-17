#include<vector>

//快速排序
void QuickSort(vector<int>& nums)
{
    _quickSort(nums, 0, nums.size()-1);
}

void _quickSort(vector<int>&nums, int start, int end)
{
    if(start<end){
        int pivot=nums[end];
        int i=start;
        for(int j=start;j<end;j++)
        {
            if(nums[j]<pivot)
            {
                swap(nums[j], nums[i]);
                i++;
            }
        }
        swap(nums[i], nums[end]);
        _quickSort(nums, start, i-1);
        _quickSort(nums, i+1, end);
    }
}

//归并排序
void MergeSort(vector<int>& nums)
{
    _mergeSort(nums, 0, nums.size()-1);
}

void _mergeSort(vector<int>& nums, int start, int end)
{
    if(start<end)
    {
        int mid=start+end>>1;
        _mergeSort(nums, start, mid);
        _mergeSort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
}

void merge(vector<int>& nums, int start, int mid, int end)
{
    vector<int> tmp(end-start+1);//频繁创建数组，可以改为全局变量
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=end)
    {
        if(nums[i]<nums[j])
        {
            tmp[k++]=nums[i++];
        }
        else
            tmp[k++]=nums[j++];
    }
    while(i<=mid)
    {
        tmp[k++]=nums[i++];
    }
    while(j<=end)
    {
        tmp[k++]=nums[j++];
    }
    for(int t=0;<tmp.size();t++)
    {
        nums[start+t]=tmp[t];
    }
}

//堆排序
void HeapSort(vector<int> nums)
{
    buildMaxHeap(nums);
    int len=nums.size();
    for(int i=nums.size();i>=0;i--)
    {
        swap(nums[i], nums[0]);
        len--;
        heapHelper(nums, 0, len);
    }
}

void buildMaxHeap(vector<int>& nums)
{
    int length=nums.size();
    for(int i=length/2;i>=0;i--)
    {
        heapHelper(nums, i, length);
    }
}

void heapHelper(vector<int>& nums, int i, int length)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<length&&nums[left]>nums[largest])
    {
        largest=left;
    }
    if(right<length&&nums[right]>nums[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(nums[i], nums[largest]);
        heapHelper(nums, largest, length);
    }
}