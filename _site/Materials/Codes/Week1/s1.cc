#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Tìm số lớn nhất trong hai số 
int max (int x, int y) {
    if (x > y) return x;
    else       return y;
}

// Thuật toán đơn giản 
int maxSub1 (int a[], int N)
{
    int maxsum = INT32_MIN;  //âm vô cùng
    int sum = 0; 
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++){
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum = sum + a[k];
            } 
            maxsum = max (sum, maxsum);  
        }
    } 
    return maxsum;
}

// Thuật toán đơn giản có cải tiến 
int maxSub2 (int a[], int N) {
    int maxsum = INT32_MIN;  //âm vô cùng
    int sum = 0; 
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = i; j < N; j++) {
           sum = sum + a[j];
            maxsum = max (sum, maxsum);
        }
    } 
    return maxsum;
}

/* Cài đặt dùng đệ quy, chia để trị */ 
// Tìm dãy con lớn nhất trong đoạn a[i],..., a[j] và kết thúc tại a[j]
int maxleft (int a[], int i, int j) 
{
    int maxsum = INT32_MIN;
    int sum = 0;
    for (int k = j; k >= i; k--){
        sum = sum + a[k];
        maxsum = max(sum, maxsum);
    }
    return maxsum;
}

// Tìm dãy con lớn nhất trong đoạn a[i],..., a[j] và bắt đầu tại a[i]
int maxright (int a[], int i, int j){
    int maxsum = INT32_MIN;
    int sum = 0;
    for (int k = i; k <= j; k++){
        sum = sum + a[k];
        maxsum = max(sum, maxsum);
    }
    return maxsum;
}

// Tìm dãy con lớn nhất a[i], a[i+1], ..., a[j]
int maxsub(int a[], int i, int j){
    if (i == j) return a[i];
    int m = (i + j)/2;
    int wL = maxsub (a, i, m);
    int wR = maxsub (a, m+1, j);
    int wM = maxleft(a, i, m) + maxright(a, m+1, j);
    return max (max(wL, wR), wM);
}
// Phiên bản đệ quy, chia để trị  
int maxsub3 (int a[], int N) {
    return maxsub (a, 0, N-1);
}

//Dung quy hoach dong
int maxsub4 (int a[], int N) {
    int maxsum = a[0];
    int e = a[0];
    for (int i = 1; i < N; i++) {
        e = max(a[i], e + a[i]);
        maxsum = max (maxsum, e);
    }
    return maxsum;
}


// Sinh dữ liệu ngẫu nhiên 
void genRandom (int a[], int N) {
    int r = 0;
    srand (time(NULL));
    for (int i = 0; i < N; i++) {
        r = rand() % 100;
        if (r > 70) a[i] = -r;    // 30% là số âm  
        else a[i] = r;            // 70% là số dương 
    }
}

#define N 100000000
int a[N]; // = {-2, 11, -4, 13, -5, 2};

int main(int argc, char const *argv[]) {
//    int N = 10000000;
    genRandom(a,N);
    cout <<maxsub4(a, N)<<endl;
    return 0;
}

