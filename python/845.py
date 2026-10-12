class Solution:
    def longestMountain(self, arr: list[int]) -> int:

        ret = 0

        for i in range(1,len(arr)-1):

            if arr[i-1] < arr[i] > arr[i+1]:
                l=r=i

                while l>0 and arr[l] > arr[l-1]:
                    l-=1
                
                while r<len(arr)-1 and arr[r] > arr[r+1]:
                    r+=1
                
                ret = max(ret, r-l+1)
        return ret
