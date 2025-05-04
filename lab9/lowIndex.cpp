// Importing necessary modules
# include <stdio.h>
# include <cstdlib>
# include <vector>
# include <algorithm>

// Main function
int main(){
    int t;
    //printf("Enter number of test cases\t");
    scanf("%d",&t);
    int k;
    int q;
    int temp;
    std::vector <int> a;
    std::vector <int> out;
    // Loop for test cases
    for (int i=0;i<t;i++){
        a.clear();
        out.clear();
       // printf("Enter k and q\t");
        scanf("%d %d",&k,&q);
       // printf("Enter a1,a2,...ak\t");
        printf("\n");
        for (int j=0;j<k;j++){
            scanf("%d",&temp);
            a.push_back(temp);
        }
        //printf("Enter n1,n2,...nq\t");
        for (int l=0;l<q;l++){
            scanf("%d",&temp);
            if (temp<a.front()){
                out.push_back(temp);
            }
            else{
                out.push_back(a.front()-1);
            }
        }
        for (int m=0;m<q;m++){
            printf("%d\t",out[m]);
        }
        printf("\n");
    }
    return 0;
}