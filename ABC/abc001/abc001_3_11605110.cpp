#include <bits/stdc++.h>
int main() {int deg,dis,w;
int wlist[13] = {0,15,93,201,327,477,645,831,1029,1245,1467,1707,1959};
char dir[16][4] = {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
scanf("%d %d",&deg,&dis);
for (w = 12;w >= 0;w--) {if (wlist[w] <= dis) {break;}}
printf("%s %d\n",w ? dir[((deg*10+1125)%36000)/2250] : "C",w);
}