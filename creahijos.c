#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define COMPROBAR 1 //Comprobar estructura (0/1)
void H0(){
printf(“H0\n”);
sleep(30);
return;
}
void N0(){
printf(“N0\n”);
sleep(30);
return;
}
void N1(){
printf(“N1\n”);
sleep(30);
return;
}
void N2(){
printf(“N2\n”);
sleep(30);
return;
}

int main(){
int i,j;
pid_t pidH, wpidH;
pid_t pidN, wpidN;
for(i=0;i<4;i++){
pidH = fork();
if(pidH == 0){
switch(i){
case 0:
H0();
exit(0);
default:
pidN = fork();
if(pidN == 0){
switch(i){
case 1:
N0();
exit(0);
case 2:
N1();
exit(0);
case 3:
N2();
exit(0);
}
}
else if(pidN <0) exit(1);
else{
wpidN = wait(NULL);
exit(0);
}
}
}
else if(pidH < 0)
exit(1);
}
if(COMPROBAR){
system("pstree -G | grep ejecutable");
system("killall ejecutable");
exit(0);
}
for(i=0;i<4;i++)
wpidH =wait(NULL);
exit(0);
}
