#include<stdio.h>
#include<stdlib.h>

int Cross_Sub_Array(int arr[],int low,int mid,int high)
{
  int left_max=-99999999;
  int left_tot=0;
  for(int i=mid;i>=low;i--)
  {
    left_tot+=arr[i];
    if(left_tot>left_max)
    {
      left_max=left_tot;
    }
  }
  int right_max=-99999999;
  int right_tot=0;
  for(int j=mid+1;j<=high;j++)
  {
    right_tot+=arr[j];
    if(right_tot>right_max)
    {
      right_max=right_tot;
    }
  }
  return right_max+left_max;
}

int Maximum_Sub_Array(int arr[],int low,int high)
{
  if(low==high)
  {
    return arr[low];
  }
  else
  {
    int mid=(low+high)/2;
    int left_sum = Maximum_Sub_Array(arr,low,mid);
    int right_sum = Maximum_Sub_Array(arr,mid+1,high);
    int cross_sum = Cross_Sub_Array(arr,low,mid,high);
    if(left_sum>=right_sum && left_sum>=cross_sum)
    {
      return left_sum;
    }
    else if(right_sum>=left_sum && right_sum>=cross_sum)
    {
      return right_sum;
    }
    else
    {
      return cross_sum;
    }
  }
}

int main()
{
  int size;
  scanf("%d",&size);
  int arr[size];
  for(int i=0;i<size;i++)
  {
    scanf("%d",&arr[i]);
  }
  int result = Maximum_Sub_Array(arr,0,size-1);
  printf("The Sum of the Maximum Sub Array : %d",result);
}