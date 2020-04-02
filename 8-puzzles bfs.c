#include <stdio.h>
#include <stdlib.h>

int check (int a[][3], int b[][3]){
	int up, down, right, left;
	int srl=0;
	int i,j;
	char s[4];
	
	up = difup (a, b);
	down = difdown (a, b);
	left = difleft (a, b);
	right = difright (a, b);
	
	int min = minimum (up, down, left, right);
	
	if (min == right)
	s[srl++] = 'r';
	if (min == left)
	s[srl++] = 'l';
	if (min == up)
	s[srl++] = 'u';
	if (min == down)
	s[srl++] = 'd';
	
	int sel = rand()%srl;			// menyimpan isi srl yang bernilai minimum
	char direction = s[sel];
	
	if (direction == 'r'){
		for (i=0; i<3; i++)
			for (j=0; j<2; j++)
			if(a[i][j]==0){
				a[i][j] = a[i][j+1];
				a[i][j+1] = 0;
				return 0;
			}
		}
	
	else if (direction == 'l'){
		for (i=0; i<3; i++)
			for (j=1; j<3; j++)
			if (a[i][j]==0){
				a[i][j] = a[i][j-1];
				a[i][j-1] = 0;
				return 0;
			}
		}
	
	else if (direction == 'u'){
		for (i=1; i<3; i++)
			for (j=0; j<3; j++)
			if (a[i][j]==0){
				a[i][j] = a[i-1][j];
				a[i-1][j] = 0;
				return 0;
			}
		}
	
	else if (direction == 'd'){
		for (i=0; i<2; i++)
			for (j=0; j<3; j++)
			if (a[i][j]==0){
				a[i][j] = a[i+1][j];
				a[i+1][j] = 0;
				return 0;
			}
		}
	return 0;
}

int difup (int a[][3], int b[][3]){
	int temp[3][3],i,j;
	
	for (i=0; i<3; i++)		//menyalin array a dalam array untuk pengujian
		for (j=0; j<3; j++)
			temp[i][j] = a[i][j];
	
	for (i=1; i<3; i++)		// swapping ke atas 
		for (j=0; j<3; j++)
			if (a[i][j]==0){
				temp[i-1][j] = 0;
				temp[i][j] = a[i-1][j];
			}
	return difference (temp, b);
}

int difdown (int a[][3], int b[][3]){
	int temp[3][3], i,j;
	
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			temp[i][j] = a[i][j];
	
	for (i=0; i<2; i++)			// swapping ke bawah
		for (j=0; j<3; j++)
			if (a[i][j]==0){
				temp[i+1][j] = 0;
				temp[i][j] = a[i+1][j];
			}
	return difference (temp,b);
}

int difleft (int a[][3], int b[][3]){
	int temp[3][3], i, j;

	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			temp[i][j] = a[i][j];
	
	for (i=0; i<3; i++)		//swapping ke kiri
		for (j=1; j<3; j++)
			if (a[i][j]==0){
				temp[i][j-1] = 0;
				temp[i][j] = a[i][j-1];

			}
	return difference (temp, b);
}

int difright (int a[][3], int b[][3]){
	int temp[3][3],i,j;
	
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			temp[i][j] = a[i][j];
	
	for (i=0; i<3; i++)		//swapping ke kanan
		for (j=0; j<2; j++)
			if (a[i][j]==0){
				temp[i][j+1] = 0;
				temp[i][j] = a[i][j+1];
			}
	return difference (temp, b);
}

int minimum (int u, int d, int l, int r){
	
	int min = u;
	if (d<min)
	min = d;
	if (l<min)
	min = l;
	if (r<min)
	min = r;
	
	return min;
}

int difference (int a[][3], int b[][3]){	// fungsi untuk cek dan mnghitung perbedaan letak angka
	int counter = 0, i, j;
	
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			if (a[i][j] != b[i][j])	counter++;

	return counter;
}

void display (int a[][3]){			
	int i,j; 
	
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf ("%d ", a[i][j]);
		}
		printf ("\n");
	}
}

int main (){
	int a[3][3] = {{2,8,3},{1,6,4},{7,0,5}};		//initial state
	int b[3][3] = {{1,2,3},{8,0,4},{7,6,5}};		//goal state
	int i,j,d;
	int steps=0;
	
	printf ("Goal state : \n");
	display(b);
	printf ("Initial state	: \n");
	display(a);
	printf ("Tekan enter untuk melanjutkan step\n");
	
	while(1){
		d = difference (a, b);			// menghitung jumlah letak angka yang berbeda antara intial state dan goal state
		if (d==0){
			printf("DONE!!!\n");
			return 0;
		}
		steps++;
		printf ("\nSteps : %d \n", steps);
		check (a, b);				// mengubah array
		display(a);
		system ("PAUSE");			// agar tidak terjadi looping 
	}
	return 0;
}
