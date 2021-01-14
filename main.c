/*
rubiks cube
*/
#include<stdio.h>

typedef struct strow0{
	char c0;	//corner0
	char e;		//edge
	char c1;	//corner1
}row0;

typedef struct strow1{
	char e0;	//edge0
	char a;		//axix
	char e1;	//edge1
}row1;

typedef struct stside{
	row0 r0;	//row0
	row1 r1;	//row1
	row0 r2;	//row2
}side;

typedef struct stcube{
	side u;		//up
	side l;		//left
	side f;		//front
	side r;		//right
	side b;		//back
	side d;		//down
}cube;

void cube_in(cube *);
void cube_print(cube c);
void cube_execmd(cube *,const char *cmd);
int cube_errcmd(const char *cmd);
void cube_u(cube *);
void cube_u_ce(cube *);
void cube_l(cube *);
void cube_l_ce(cube *);
void cube_f(cube *);
void cube_f_ce(cube *);
void cube_r(cube *);
void cube_r_ce(cube *);
void cube_b(cube *);
void cube_b_ce(cube *);
void cube_d(cube *);
void cube_d_ce(cube *);
void cube_x(cube *);
void cube_y(cube *);
void cube_z(cube *);
int cube_sol(cube c);
int n=0;

main(){
	cube c;
	char cmd[50];
	int s=0;
input:
	cube_in(&c);
	cube_print(c);
L1:
	s=cube_sol(c);
	if(s==6){
		printf("The cube is solved...\nTry one more cube...\n");
		goto input;
	}
	printf("Enter command : ");
	scanf("%s",cmd);
	cube_execmd(&c,cmd);
	cube_print(c);
	printf("Total step: %d\n",n);
	goto L1;
}
///////////////////////////////////////////////////////////////
int cube_sol(cube c){
int s=0;
char t;
t=c.u.r1.a;
if(t==c.u.r0.c0 && t==c.u.r0.e && t==c.u.r0.c1 && t==c.u.r1.e0 && t==c.u.r1.e1 && t==c.u.r2.c0 && t==c.u.r2.e && t==c.u.r2.c1){
	s++;
}
t=c.l.r1.a;
if(t==c.l.r0.c0 && t==c.l.r0.e && t==c.l.r0.c1 && t==c.l.r1.e0 && t==c.l.r1.e1 && t==c.l.r2.c0 && t==c.l.r2.e && t==c.l.r2.c1){
	s++;
}
t=c.f.r1.a;
if(t==c.f.r0.c0 && t==c.f.r0.e && t==c.f.r0.c1 && t==c.f.r1.e0 && t==c.f.r1.e1 && t==c.f.r2.c0 && t==c.f.r2.e && t==c.f.r2.c1){
	s++;
}
t=c.r.r1.a;
if(t==c.r.r0.c0 && t==c.r.r0.e && t==c.r.r0.c1 && t==c.r.r1.e0 && t==c.r.r1.e1 && t==c.r.r2.c0 && t==c.r.r2.e && t==c.r.r2.c1){
	s++;
}
t=c.b.r1.a;
if(t==c.b.r0.c0 && t==c.b.r0.e && t==c.b.r0.c1 && t==c.b.r1.e0 && t==c.b.r1.e1 && t==c.b.r2.c0 && t==c.b.r2.e && t==c.b.r2.c1){
	s++;
}
t=c.d.r1.a;
if(t==c.d.r0.c0 && t==c.d.r0.e && t==c.d.r0.c1 && t==c.d.r1.e0 && t==c.d.r1.e1 && t==c.d.r2.c0 && t==c.d.r2.e && t==c.d.r2.c1){
	s++;
}
return s;
}
///////////////////////////////////////////////////////////////
void cube_execmd(cube *c,const char *cmd){
	int i=0,error=0;
	error=cube_errcmd(cmd);
	if(error==0){
		for(i=0;cmd[i];i++){
			if(cmd[i+1]!='2' && cmd[i+1]!='\''){
				switch(cmd[i]){
					case 'u':cube_u(c);break;
					case 'l':cube_l(c);break;
					case 'f':cube_f(c);break;
					case 'r':cube_r(c);break;
					case 'b':cube_b(c);break;
					case 'd':cube_d(c);break;
					case 'x':cube_x(c);break;
					case 'y':cube_y(c);break;
					case 'z':cube_z(c);break;
					//default:error=1;printf("Invalid comand... Try again...\n");break;
				}
				n++;
			}
			else if(cmd[i+1]=='2'){
				switch(cmd[i]){
					case 'u':cube_u(c);cube_u(c);break;
					case 'l':cube_l(c);cube_l(c);break;
					case 'f':cube_f(c);cube_f(c);break;
					case 'r':cube_r(c);cube_r(c);break;
					case 'b':cube_b(c);cube_b(c);break;
					case 'd':cube_d(c);cube_d(c);break;
					case 'x':cube_x(c);cube_x(c);break;
					case 'y':cube_y(c);cube_y(c);break;
					case 'z':cube_z(c);cube_z(c);break;
					//default:error=1;printf("Invalid comand... Try again...\n");break;
				}
				i++;
				n++;
			}
			else if(cmd[i+1]=='\''){	
				switch(cmd[i]){
					case 'u':cube_u(c);cube_u(c);cube_u(c);break;
					case 'l':cube_l(c);cube_l(c);cube_l(c);break;
					case 'f':cube_f(c);cube_f(c);cube_f(c);break;
					case 'r':cube_r(c);cube_r(c);cube_r(c);break;
					case 'b':cube_b(c);cube_b(c);cube_b(c);break;
					case 'd':cube_d(c);cube_d(c);cube_d(c);break;
					case 'x':cube_x(c);cube_x(c);cube_x(c);break;
					case 'y':cube_y(c);cube_y(c);cube_y(c);break;
					case 'z':cube_z(c);cube_z(c);cube_z(c);break;
					//default:error=1;printf("Invalid comand... Try again...\n");break;
				}
				i++;
				n++;
			}
		}
	}
	else
		printf("Invalid command... Try again...\n");
}
////////////////////////////////
int cube_errcmd(const char *cmd){
int i=0,error=0;
for(i=0;cmd[i];i++){
	if(i==0 && (cmd[0]=='2' || cmd[0]=='\'')){
		error=1;
		break;
	}
	else if(cmd[i+1]!='2' && cmd[i+1]!='\''){
		if(cmd[i]!='u'&&cmd[i]!='l'&&cmd[i]!='f'&&cmd[i]!='r'&&cmd[i]!='b'&&cmd[i]!='d'&&cmd[i]!='x'&&cmd[i]!='y'&&cmd[i]!='z'){
			error=1;
			break;
		}
	}
	else if(cmd[i+1]=='2'||cmd[i+1]=='\''){
		if(cmd[i]!='u'&&cmd[i]!='l'&&cmd[i]!='f'&&cmd[i]!='r'&&cmd[i]!='b'&&cmd[i]!='d'&&cmd[i]!='x'&&cmd[i]!='y'&&cmd[i]!='z'){
			error=1;
			break;
		}
		i++;
	}
	else{
		error=1;
		break;
	}
}
return error;
}
/////////////////////////////
void cube_u(cube *c){
row0 temp_row0;
printf("Up side +90\n");
temp_row0=c->f.r0;
c->f.r0=c->r.r0;
c->r.r0=c->b.r0;
c->b.r0=c->l.r0;
c->l.r0=temp_row0;

cube_u_ce(c);
}
//
void cube_u_ce(cube *c){
char temp;
temp=c->u.r0.c0;
c->u.r0.c0=c->u.r2.c0;
c->u.r2.c0=c->u.r2.c1;
c->u.r2.c1=c->u.r0.c1;
c->u.r0.c1=temp;

temp=c->u.r0.e;
c->u.r0.e=c->u.r1.e0;
c->u.r1.e0=c->u.r2.e;
c->u.r2.e=c->u.r1.e1;
c->u.r1.e1=temp;

}
/////////////////////////
void cube_l(cube *c){
char temp;
printf("Left side +90\n");
temp=c->f.r0.c0;
c->f.r0.c0=c->u.r0.c0;
c->u.r0.c0=c->b.r2.c1;
c->b.r2.c1=c->d.r0.c0;
c->d.r0.c0=temp;

temp=c->f.r2.c0;
c->f.r2.c0=c->u.r2.c0;
c->u.r2.c0=c->b.r0.c1;
c->b.r0.c1=c->d.r2.c0;
c->d.r2.c0=temp;

temp=c->f.r1.e0;
c->f.r1.e0=c->u.r1.e0;
c->u.r1.e0=c->b.r1.e1;
c->b.r1.e1=c->d.r1.e0;
c->d.r1.e0=temp;

cube_l_ce(c);
}
///////////////////////
void cube_l_ce(cube *c){
char temp;
temp=c->l.r0.c0;
c->l.r0.c0=c->l.r2.c0;
c->l.r2.c0=c->l.r2.c1;
c->l.r2.c1=c->l.r0.c1;
c->l.r0.c1=temp;

temp=c->l.r0.e;
c->l.r0.e=c->l.r1.e0;
c->l.r1.e0=c->l.r2.e;
c->l.r2.e=c->l.r1.e1;
c->l.r1.e1=temp;

}
///////////////////////
void cube_f(cube *c){
char temp;
printf("Front side +90\n");
temp=c->u.r2.c0;
c->u.r2.c0=c->l.r2.c1;
c->l.r2.c1=c->d.r0.c1;
c->d.r0.c1=c->r.r0.c0;
c->r.r0.c0=temp;

temp=c->u.r2.c1;
c->u.r2.c1=c->l.r0.c1;
c->l.r0.c1=c->d.r0.c0;
c->d.r0.c0=c->r.r2.c0;
c->r.r2.c0=temp;

temp=c->u.r2.e;
c->u.r2.e=c->l.r1.e1;
c->l.r1.e1=c->d.r0.e;
c->d.r0.e=c->r.r1.e0;
c->r.r1.e0=temp;

cube_f_ce(c);

}
///////////////////////
void cube_f_ce(cube *c){
char temp;
temp=c->f.r0.c0;
c->f.r0.c0=c->f.r2.c0;
c->f.r2.c0=c->f.r2.c1;
c->f.r2.c1=c->f.r0.c1;
c->f.r0.c1=temp;

temp=c->f.r0.e;
c->f.r0.e=c->f.r1.e0;
c->f.r1.e0=c->f.r2.e;
c->f.r2.e=c->f.r1.e1;
c->f.r1.e1=temp;

}
//////////////////////
void cube_r(cube *c){
char temp;
printf("Right side +90\n");
temp=c->f.r0.c1;
c->f.r0.c1=c->d.r0.c1;
c->d.r0.c1=c->b.r2.c0;
c->b.r2.c0=c->u.r0.c1;
c->u.r0.c1=temp;

temp=c->f.r2.c1;
c->f.r2.c1=c->d.r2.c1;
c->d.r2.c1=c->b.r0.c0;
c->b.r0.c0=c->u.r2.c1;
c->u.r2.c1=temp;

temp=c->f.r1.e1;
c->f.r1.e1=c->d.r1.e1;
c->d.r1.e1=c->b.r1.e0;
c->b.r1.e0=c->u.r1.e1;
c->u.r1.e1=temp;
cube_r_ce(c);
}
////////////////////////
void cube_r_ce(cube *c){
char temp;
temp=c->r.r0.c0;
c->r.r0.c0=c->r.r2.c0;
c->r.r2.c0=c->r.r2.c1;
c->r.r2.c1=c->r.r0.c1;
c->r.r0.c1=temp;

temp=c->r.r0.e;
c->r.r0.e=c->r.r1.e0;
c->r.r1.e0=c->r.r2.e;
c->r.r2.e=c->r.r1.e1;
c->r.r1.e1=temp;

}
//
void cube_b(cube *c){
char temp;
printf("Back side +90\n");
temp=c->u.r0.c0;
c->u.r0.c0=c->r.r0.c1;
c->r.r0.c1=c->d.r2.c1;
c->d.r2.c1=c->l.r2.c0;
c->l.r2.c0=temp;

temp=c->u.r0.c1;
c->u.r0.c1=c->r.r2.c1;
c->r.r2.c1=c->d.r2.c0;
c->d.r2.c0=c->l.r0.c0;
c->l.r0.c0=temp;

temp=c->u.r0.e;
c->u.r0.e=c->r.r1.e1;
c->r.r1.e1=c->d.r2.e;
c->d.r2.e=c->l.r1.e0;
c->l.r1.e0=temp;

cube_b_ce(c);
}
//////////////////////
void cube_b_ce(cube *c){
char temp;
temp=c->b.r0.c0;
c->b.r0.c0=c->b.r2.c0;
c->b.r2.c0=c->b.r2.c1;
c->b.r2.c1=c->b.r0.c1;
c->b.r0.c1=temp;

temp=c->b.r0.e;
c->b.r0.e=c->b.r1.e0;
c->b.r1.e0=c->b.r2.e;
c->b.r2.e=c->b.r1.e1;
c->b.r1.e1=temp;

}
////////////////////////
void cube_d(cube *c){
row0 temp_row0;
char temp;
printf("Down side +90\n");
temp_row0=c->f.r2;
c->f.r2=c->l.r2;
c->l.r2=c->b.r2;
c->b.r2=c->r.r2;
c->r.r2=temp_row0;
cube_d_ce(c);
}
/////////////////////////
void cube_d_ce(cube *c){
char temp;
temp=c->d.r0.c0;
c->d.r0.c0=c->d.r2.c0;
c->d.r2.c0=c->d.r2.c1;
c->d.r2.c1=c->d.r0.c1;
c->d.r0.c1=temp;

temp=c->d.r0.e;
c->d.r0.e=c->d.r1.e0;
c->d.r1.e0=c->d.r2.e;
c->d.r2.e=c->d.r1.e1;
c->d.r1.e1=temp;

}
///////////////////////
void cube_x(cube *c){

}
//
void cube_y(cube *c){

}
//
void cube_z(cube *c){

}
/////////////////////////////////////////
void cube_print(cube c){
	//41=red 42=green 43=yellow 44=blue 45=purple(orange) 46=sky 47=white
	char colour;
	int i=0;
	printf("Cube status:\n");
	for(i=0;i<54;i++){

		if(i==0||i==3||i==6||i==45||i==48||i==51){
			printf("       ");
		}


		switch(i){
			case 0:colour=c.u.r0.c0;break;
			case 1:colour=c.u.r0.e;break;
			case 2:colour=c.u.r0.c1;break;
			case 3:colour=c.u.r1.e0;break;
			case 4:colour=c.u.r1.a;break;
			case 5:colour=c.u.r1.e1;break;
			case 6:colour=c.u.r2.c0;break;
			case 7:colour=c.u.r2.e;break;
			case 8:colour=c.u.r2.c1;break;

			case 9:colour=c.l.r0.c0;break;
			case 10:colour=c.l.r0.e;break;
			case 11:colour=c.l.r0.c1;break;
			case 12:colour=c.f.r0.c0;break;
			case 13:colour=c.f.r0.e;break;
			case 14:colour=c.f.r0.c1;break;
			case 15:colour=c.r.r0.c0;break;
			case 16:colour=c.r.r0.e;break;
			case 17:colour=c.r.r0.c1;break;
			case 18:colour=c.b.r0.c0;break;
			case 19:colour=c.b.r0.e;break;
			case 20:colour=c.b.r0.c1;break;

			case 21:colour=c.l.r1.e0;break;
			case 22:colour=c.l.r1.a;break;
			case 23:colour=c.l.r1.e1;break;
			case 24:colour=c.f.r1.e0;break;
			case 25:colour=c.f.r1.a;break;
			case 26:colour=c.f.r1.e1;break;
			case 27:colour=c.r.r1.e0;break;
			case 28:colour=c.r.r1.a;break;
			case 29:colour=c.r.r1.e1;break;
			case 30:colour=c.b.r1.e0;break;
			case 31:colour=c.b.r1.a;break;
			case 32:colour=c.b.r1.e1;break;

			case 33:colour=c.l.r2.c0;break;
			case 34:colour=c.l.r2.e;break;
			case 35:colour=c.l.r2.c1;break;
			case 36:colour=c.f.r2.c0;break;
			case 37:colour=c.f.r2.e;break;
			case 38:colour=c.f.r2.c1;break;
			case 39:colour=c.r.r2.c0;break;
			case 40:colour=c.r.r2.e;break;
			case 41:colour=c.r.r2.c1;break;
			case 42:colour=c.b.r2.c0;break;
			case 43:colour=c.b.r2.e;break;
			case 44:colour=c.b.r2.c1;break;

			case 45:colour=c.d.r0.c0;break;
			case 46:colour=c.d.r0.e;break;
			case 47:colour=c.d.r0.c1;break;
			case 48:colour=c.d.r1.e0;break;
			case 49:colour=c.d.r1.a;break;
			case 50:colour=c.d.r1.e1;break;
			case 51:colour=c.d.r2.c0;break;
			case 52:colour=c.d.r2.e;break;
			case 53:colour=c.d.r2.c1;break;

		}
		switch(colour){
			case 'r':printf("\033[41m__\033[0m");break;
			case 'g':printf("\033[42m__\033[0m");break;
			case 'w':printf("\033[47m__\033[0m");break;
			case 'b':printf("\033[44m__\033[0m");break;
			case 'y':printf("\033[43m__\033[0m");break;
			case 'o':printf("\033[45m__\033[0m");break;
		}
		if(i==11||i==14||i==17||i==23||i==26||i==29||i==35||i==38||i==41){
			printf(" ");
		}

		if(i==2||i==5||i==8||i==20||i==32||i==44||i==47||i==50||i==53){
			printf("\n");
		}

	}
	/*
	   printf("    %c%c%c\n",c.u.r0.c0,c.u.r0.e,c.u.r0.c1);
	   printf("    %c%c%c\n",c.u.r1.e0,c.u.r1.a,c.u.r1.e1);
	   printf("    %c%c%c\n",c.u.r2.c0,c.u.r2.e,c.u.r2.c1);

	   printf("%c%c%c ",c.l.r0.c0,c.l.r0.e,c.l.r0.c1);
	   printf("%c%c%c ",c.f.r0.c0,c.f.r0.e,c.f.r0.c1);
	   printf("%c%c%c ",c.r.r0.c0,c.r.r0.e,c.r.r0.c1);
	   printf("%c%c%c\n",c.b.r0.c0,c.b.r0.e,c.b.r0.c1);

	   printf("%c%c%c ",c.l.r1.e0,c.l.r1.a,c.l.r1.e1);
	   printf("%c%c%c ",c.f.r1.e0,c.f.r1.a,c.f.r1.e1);
	   printf("%c%c%c ",c.r.r1.e0,c.r.r1.a,c.r.r1.e1);
	   printf("%c%c%c\n",c.b.r1.e0,c.b.r1.a,c.b.r1.e1);

	   printf("%c%c%c ",c.l.r2.c0,c.l.r2.e,c.l.r2.c1);
	   printf("%c%c%c ",c.f.r2.c0,c.f.r2.e,c.f.r2.c1);
	   printf("%c%c%c ",c.r.r2.c0,c.r.r2.e,c.r.r2.c1);
	   printf("%c%c%c\n",c.b.r2.c0,c.b.r2.e,c.b.r2.c1);

	   printf("    %c%c%c\n",c.d.r0.c0,c.d.r0.e,c.d.r0.c1);
	   printf("    %c%c%c\n",c.d.r1.e0,c.d.r1.a,c.d.r1.e1);
	   printf("    %c%c%c\n",c.d.r2.c0,c.d.r2.e,c.d.r2.c1);
	 */
}
////////////////////////////////////////////////////////////////////
void cube_in(cube *c){
	printf("Hold the cube as mentioned:\n");
	printf("Left:\033[42m__\033[0m front:\033[47m__\033[0m Right:\033[44m__\033[0m \n");

	printf("Up side: (r) \033[41m__\033[0m\n");
	scanf("%c%c%c",&c->u.r0.c0,&c->u.r0.e,&c->u.r0.c1);
	scanf(" %c%c%c",&c->u.r1.e0,&c->u.r1.a,&c->u.r1.e1);
	scanf(" %c%c%c",&c->u.r2.c0,&c->u.r2.e,&c->u.r2.c1);

	printf("Left side: (g) \033[42m__\033[0m\n");
	scanf(" %c%c%c",&c->l.r0.c0,&c->l.r0.e,&c->l.r0.c1);
	scanf(" %c%c%c",&c->l.r1.e0,&c->l.r1.a,&c->l.r1.e1);
	scanf(" %c%c%c",&c->l.r2.c0,&c->l.r2.e,&c->l.r2.c1);

	printf("Front side: (w) \033[47m__\033[0m\n");
	scanf(" %c%c%c",&c->f.r0.c0,&c->f.r0.e,&c->f.r0.c1);
	scanf(" %c%c%c",&c->f.r1.e0,&c->f.r1.a,&c->f.r1.e1);
	scanf(" %c%c%c",&c->f.r2.c0,&c->f.r2.e,&c->f.r2.c1);

	printf("Right side: (b) \033[44m__\033[0m\n");
	scanf(" %c%c%c",&c->r.r0.c0,&c->r.r0.e,&c->r.r0.c1);
	scanf(" %c%c%c",&c->r.r1.e0,&c->r.r1.a,&c->r.r1.e1);
	scanf(" %c%c%c",&c->r.r2.c0,&c->r.r2.e,&c->r.r2.c1);

	printf("Back side: (y) \033[43m__\033[0m\n");
	scanf(" %c%c%c",&c->b.r0.c0,&c->b.r0.e,&c->b.r0.c1);
	scanf(" %c%c%c",&c->b.r1.e0,&c->b.r1.a,&c->b.r1.e1);
	scanf(" %c%c%c",&c->b.r2.c0,&c->b.r2.e,&c->b.r2.c1);

	printf("Down side: (o) \033[45m__\033[0m\n");
	scanf(" %c%c%c",&c->d.r0.c0,&c->d.r0.e,&c->d.r0.c1);
	scanf(" %c%c%c",&c->d.r1.e0,&c->d.r1.a,&c->d.r1.e1);
	scanf(" %c%c%c",&c->d.r2.c0,&c->d.r2.e,&c->d.r2.c1);

}
//end of project
//
