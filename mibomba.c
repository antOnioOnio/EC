// gcc -Og bomba.c -o bomba -no-pie -fno-guess-branch-probability

#include <stdio.h>	// para printf(), fgets(), scanf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()
#include <sys/time.h>	// para gettimeofday(), struct timeval

#define SIZE 100
#define TLIM 5


// password---> ""ap C me A oe P oe I jf T af A se N et \n""
char password[]="cmeaoepoeijftafasenet\n";	// contraseña
// pin sera 10000/2 + 25 = 5025
int  passcode  = 10000;				// pin


int checkPassword(char *c){
    int i = 0 ;
    int counter = 0;
    char finalPass[8];

    finalPass[0] = password[0];
    finalPass[1] = password[3];
    finalPass[2] = password[6];
    finalPass[3] = password[9];
    finalPass[4] = password[12];
    finalPass[5] = password[15];
    finalPass[6] = password[18];

    if ( finalPass[0] == c[0] && finalPass[1] == c[1] && 
         finalPass[2] == c[2] && finalPass[3] == c[3] && 
         finalPass[4] == c[4] && finalPass[5] == c[5] && 
         finalPass[6] == c[6]  ){
             return 1;
         }else {

            return 0;
         }
}


int checkPin(int number){

    passcode = (passcode / 2 ) + 25 ; //----> 5025
    
    if ( number != passcode){
        return 0;
    }

    return 1;

}

void boom(void){
	printf(	"\n"
		"***************\n"
		"*** BOOM!!! ***\n"
		"***************\n"
		"\n");
	exit(-1);
}

void defused(void){
	printf(	"\n"
		"·························\n"
		"··· bomba desactivada ···\n"
		"·························\n"
		"\n");
	exit(0);
}



int main(){
	char pw[SIZE];
	int  pc, n;
	struct timeval tv1,tv2;	// gettimeofday() secs-usecs
	gettimeofday(&tv1,NULL);

	printf("Introduce la contraseña:\n");
	fgets(pw, SIZE, stdin);

	if    (	checkPassword(pw) == 0 )
	    boom();

	gettimeofday(&tv2,NULL);
	if    ( tv2.tv_sec - tv1.tv_sec > TLIM )
	    boom();

    printf("Introduce el pin: \n");
    scanf("%i", &n);

	if ( checkPin(n) == 0){
        boom();
    } 

	gettimeofday(&tv1,NULL);
	if    ( tv1.tv_sec - tv2.tv_sec > TLIM )
	    boom();

	defused();
}

// focus cmd para enfocarse en eso

// saltarse primera comprobacion----> set eax ==> 0
// saltarse la siguiente comprobacion set eax ==> 0
// hay que darle a control L porque se estropea noseque
// x/1dw $srp+0xc
// set eax=1234


// set *(char *) 0x4007c9=0xeb --> cambiamos el valor de la direccao
// set {char } es lo mismo

// coger programa y cifrar contraseña y pin a mano
// cifrar lo que teclea el usuario y comparar
// subirlo a swad a archivos-> compartidos-> 

//br *main+91

// set $eax=0x1

// br *main+125

// set $rax=0

// next

//br *main+179
//br *main+213





/**

br *main+134

br *esta_funcion_no_hace_explotar


Primer salto
br *main+130
set $al=0

Segundo salto
br *main+164
set $rax=0



Tercer salto
escanea en 219

br *main+221

br *main+242


set $ebx=0x1

br *main+260

pin = 30 ?

br *main+297
*/