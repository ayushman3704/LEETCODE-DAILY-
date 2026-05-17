class Solution { 
public:
    int countKthRoots(int l, int r, int k) {
        
        if(k == 1)
        return (r-l)+1;

        int count = 0;
        // int j = 0;
        // for(int i = 0; pow(i, k) <= l; i++){
        //     if(pow(i, k) >= l){
        //         j = i;
        //         break;
        //     }
        // }

        for(int j = 0; pow(j, k) <= r; j++){

            if(pow(j, k) >= l && pow(j, k) <= r)
            count++;
        }  

        return count;     
    }
};