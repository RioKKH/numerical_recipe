#include <cstdio>
#include <cstring> // memcpy

int main(void)
{
    double a;
    char c[sizeof(a)]; // char型のデータサイズは1バイト
    int i, j, k;

    printf("数字を入力してください --> \n");
    scanf("%lf", &a);

    memcpy(c, &a, sizeof(a)); // aの内容を配列cにコピーする
    printf("sEEEEEEE EEEEdddd dddddddd... \n");

    for (i = sizeof(a) - 1; i >= 0; i--)
    {
        for (j = sizeof(c[i]) * 8 - 1; j >= 0; j--)
        {
            k = c[i] & (i << j); // jを一つずつずらして論理積をとる
            printf("%d", k ? 1 : 0); // k = 0でなければ1、k = 0ならば0を表示する
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}
