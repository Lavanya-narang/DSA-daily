class Solution {
public:
    void merge(vector<int>&nums,int left,int mid,int right)
    {
        int n1=mid-left+1;
        int n2=right-mid;
        int arr[n1];
        int arr1[n2];
        for(int i=0;i<n1;i++)
        {
            arr[i]=nums[left+i];
        }
        for(int i=0;i<n2;i++)
        {
            arr1[i]=nums[mid+1+i];
        }
        int i=0,j=0,k=left;
        while(i<n1 && j<n2)
        {
            if(arr[i]<arr1[j])
            {
                nums[k]=arr[i];
                i++;
            }
            else
            {
                nums[k]=arr1[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            nums[k]=arr[i];
            i++;k++;
        }
        while(j<n2)
        {
            nums[k]=arr1[j];
            j++;k++;
        }
    }
    void mergesort(vector<int>&nums,int left,int right)
    {
        if(left>=right)
        {
            return;
        }
        int mid=left+(right-left)/2;
        mergesort(nums,left,mid);
        mergesort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) 
    {
      mergesort(nums,0,nums.size()-1);
      return nums;
    }
};
