#Include <stdio.h>

int lower_bound(vector<int>& data, int target){
    int begin = 0;
    int end = data.size();
    
    while(begin < end) {
    	int mid = (begin + end) / 2;
        
        if(data[mid] >= target) {
        	end = mid;
        }
        else {
        	begin = mid + 1;
        }
    }
    return end;
}
