#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define n 4
int queen[n + 1];
void Show() { /* 输出所有皇后摆放方案 */
int i;
printf("(");
for (i = 1; i <= n; i ++ ) {
printf(" %d", queen[i]);
}
printf(")\n");
}

int Place(int j) { /* 检查当前列能否放置皇后，不能放返回 0，能放返回 1 */
int i;
for (i = 1; i < j; i ++ ) { /*检查与已摆放的皇后是否在同一列或者同一斜线上*/
if ( queen[i]==queen[j]|| abs(queen[i] - queen[j]) == (j - i)) {
return 0;
}
}
return 1 ;
}
void Nqueen(int j) {
int i;
for (i = 1; i <= n; i ++ ) {
queen[j] = i;
if ( Place(j)) {
if (j == n) { /* 如果所有皇后都摆放好，则输出当前摆放方案 */
Show();
} else { /* 否则继续摆放下一个皇后 */
 Nqueen(j+1) ;
}
}
}
}
int main() {
Nqueen(1);
system("pause");
return 0;
}