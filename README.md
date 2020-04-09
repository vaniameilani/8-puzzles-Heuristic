# 8-puzzles-Heuristic

8 Queens adalah salah satu permainan strategi sederhana dimana tersedia sebuah papan yang berukuran 3x3 ( berisi 9 kotak kecil ), 
dimana terdapat salah satu kotak kosong untuk pergerakan kotak lainnya yang berisi angka 1-8. 
Dalam permainan ini, ada istilah "Initial State" dimana state awal yang telah ditentukan sebelumnya dan "Goal State" dimana state akhir atau state tujuan yang menjadi solusi akhir dari "Initial State" tersebut.

Dalam solusi dapat digunakan banyak cara, salah satunya yaitu Heuristic. Heuristic Search merupakan metode pencarian yang memperhatikan nilai heuristik (nilai perkiraan).Heuristic Search memperkirakan jarak menuju Goal (yang disebut dengan fungsi heuristik).
Fungsi heuristik ini digunakan untuk mengevaluasi keadaan-keadaan problema individual dan menentukan seberapa jauh hal tersebut dapat digunakan untuk mendapatkan solusi yang diinginkan.
Heuristik ini sendiri memiliki beberapa macam, salah satunya adalah BFS (Breath First Search). Fungsi Heuristik yang digunakan merupakan prakiraan (estimasi) cost dari initial state ke goal state, yang dinyatakan dengan :
f’ = g + h’

dimana f’ = prakiraan cost dari initial ke goal
g = cost dari initial state ke current state
h’ = prakiraan cost dari current state ke goal state

Dalam BFS ini terdapat 2 jenis algoritma, dan program ini menggunakan A* Algorithm, algoritma yang mencari jalur terpendek dari Initial State hingga Goal State.

Dalam program ini   : 
INITIAL STATE  = {2,8,3},{1,6,4},{7,0,5}
GOAL STATE     = {1,2,3},{8,0,4},{7,6,5}
angka 0 menandakan kotak kosong. 

![puzzle8](https://user-images.githubusercontent.com/61219556/78860686-0012ca00-7a5d-11ea-857b-fde0da62b81c.PNG)

Dalam pencariannya, program memiliki fungsi Different dimana untuk menghitung perbedaan letak angka pada Initial state dan Goal State tersebut. Selain itu, dihitung pula dengan kemungkinan-kemungkinan yang ada, seperti menghitung apabila angka 0 digeser keatas / ke kanan / ke kiri. Dari kemungkinan tersebut, maka angka 0 akan bergerak dengan jumlah perbedaan angka yang paling minimum pada puzzle. Proses akan berlanjut seperti itu hingga mencapai Goal State. 

```
int difference (int a[][3], int b[][3]){	// fungsi untuk cek dan mnghitung perbedaan letak angka
	int counter = 0, i, j;
	
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			if (a[i][j] != b[i][j])	counter++;

	return counter;
}
```
Fungsi untuk menghitung perbedaan pada puzzle.

```
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
```
Fungsi untuk menentukan jumlah minimum dari perbedaan-perbedaan letak angka pada puzzle. 

Untuk jumlah step dari initial state menuju goal state dalam program ini berjumlah 5 steps. 

![puzzle82](https://user-images.githubusercontent.com/61219556/78860729-1a4ca800-7a5d-11ea-84db-91a19814cabd.PNG)

~
