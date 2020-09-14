#include<bits/stdc++.h>
#define LIM 1010

using namespace std;


vector < int > bord[12][12];
int input[12] ;
int input2[12];
int temp_bord[12][12] , t;
int col_cnt[12] , row_cnt[12];
int row_number[12];
int row_point[12];
bool se[1010];
bool fin = false;



vector < int > get_the_factor(int number){

    vector < int > ans;
    int k = sqrt(number) , temp ;
    for(int i = 1 ; i <= k ; ++i){
        if(number % i == 0){
            ans.push_back(i);
            temp = (number / i);
            if(i != temp) ans.push_back(temp);
        }
    }
    sort(ans.begin() , ans.end());

    return ans;
}


void back_track(int row){

    if(row >= t){

        bool flag = true;
        for(int i = 0 ; i < t ; ++i){
            int pro = 1;
            for(int j = 0 ; j < t ; ++j){
                if(temp_bord[j][i] != 0) pro = pro * temp_bord[j][i];
            }
            if(pro != input[i]) { flag = false; break; }
        }

        if(flag) {
            fin = true;
            for(int i = 0 ; i < t ; ++i){
                for(int j = 0 ; j < t ; ++j){
                    printf("%4d" , temp_bord[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }

        return ;
    }

    if(fin) return;

    for(int i = 0 ; i < t ; ++i){
        for(int j = i + 1 ; j < t ; ++j){
            for(int k = 0 ; k < bord[row][i].size() ; ++k){
                for(int l = 0 ; l < bord[row][j].size() ; ++l){

                    if(se[bord[row][i][k]]) continue;
                    if(se[bord[row][j][l]]) continue;

                    if(row_point[i] <= 1 && row_point[j] <= 1 && bord[row][i][k] * bord[row][j][l] == input2[row] ){

                        if(row_point[i] == 0) row_number[i] = bord[row][i][k];
                        else if(row_number[i] * bord[row][i][k] != input[i]) continue;

                        if(row_point[j] == 0) row_number[j] = bord[row][j][l];
                        else if(row_number[j] * bord[row][j][l] != input[j]) continue;

                        se[bord[row][i][k]] = true;
                        se[bord[row][j][l]] = true;

                        row_point[i]++;
                        row_point[j]++;
                        temp_bord[row][i] = bord[row][i][k];
                        temp_bord[row][j] = bord[row][j][l];

                        back_track(row + 1);

                        temp_bord[row][i] = temp_bord[row][j] = 0;
                        row_point[i]--;
                        row_point[j]--;

                        se[bord[row][i][k]] = false;
                        se[bord[row][j][l]] = false;

                    }
                    if(fin) return;
                }
                if(fin) return;
            }
            if(fin) return;
        }
        if(fin) return;
    }
}



int main()
{
    //freopen("input.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);


    int num ;
    while(scanf("%d" , &t) && t){

        memset(input , 0 , sizeof(input));
        memset(input2 , 0 , sizeof(input2));
        memset(temp_bord , 0 , sizeof(temp_bord));
        memset(col_cnt , 0 , sizeof(col_cnt));
        memset(row_cnt , 0 , sizeof(row_cnt));
        memset(row_number , 0 , sizeof(row_number));
        memset(row_point , 0 , sizeof(row_point));
        memset(se , 0 , sizeof(se));


        for(int i = 0 ; i < t ; ++i){
            scanf("%d" , &num);
            input[i] = num;
        }

        for(int i = 0 ; i < t ; ++i){
            scanf("%d" , &num);
            input2[i] = num;
            for(int j = 0 ; j < t ; ++j){
                bord[i][j].clear();
                bord[i][j] = get_the_factor(__gcd(num , input[j]));
            }
        }

        back_track(0);

        fin = false;
    }
    return 0;
}
