/*https://projecteuler.net/problem=11*/
#include <stdio.h>
	
int main(int argc, char **argv)
{
	int input[] = 
	{
	8,2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 07, 78, 52, 12, 50, 77, 91, 8, 
	49,49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0,
	81,49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65,
	52,70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91,
	22,31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
	24,47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
	32,98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
	67,26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
	24,55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
	21,36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95,
	78,17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92,
	16,39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57,
	86,56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
	19,80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40,
	4,52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
	88,36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
	4,42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
	20,69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16,
	20,73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54,
	1,70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48
	};

	// this is much easier if you do it in a two dimensional array
	// this is broken; i will fix it later <3

	long int max_left = 0, max_right = 0, max_up = 0, max_down = 0, max_diag_l = 0, max_diag_r = 0;
	long int mult_left = 0, mult_right = 0, mult_up = 0, mult_down = 0, mult_diag_l , mult_diag_r = 0;
	int idx = 0, row = 1;
	int count = 0;
	for (int i = 0; i < 400; i++,count++)
	{
		printf("%d\n",row);
		mult_left = input[i];
		printf("left\t%d ", mult_left);
		for (int l = i + 1; l <= (i + 3); l++)
		{
			if (l < (row * 20)){
				printf("%d ", input[l]);
				mult_left *= input[l];
			}
		}
		if (mult_left > max_left) max_left = mult_left;

		printf("\n");
		mult_right = input[i];
		printf("right\t%d ", mult_right);
		for (int r = i - 1; r >= i - 3 ; r--)
		{
			// 70 (380)1 (379)54 (378)50
			// i -> 99  ; r = 98; row = 4 
			// 4*20 ( 80 ) > 98 > 3 * 20 (60)
			// 5*20 ( 100) > 98 > 8:0 
			// 400; r = 389
			printf("(%d)",r);
			if ((row * 20) - (17)< r < (row  * 20))
			{
				printf("%d ",input[r]);
				mult_right *= input[r];
			}
		}
		if (mult_right > max_right) max_right = mult_right;

		printf("\n");
		
		mult_down = input[i];
		printf("down\t%d ", mult_down);
		for (int d = i + 20; d <= (i + (19 * 4)); d += 20) 
		{
			if (d >= 399) break;
			printf("%d ", input[d]);
			mult_down *= input[d];
		}
		if (mult_down > max_down ) max_down = mult_down;
		printf("\n");
	
		mult_up = input[i];
		printf("up\t%d ", mult_up);
		for (int u = i - 20; u >= (i - (19 * 4)); u -= 20)
		{
			if (u < 0) break;
			printf("%d ", input[u]);
			mult_down *= input[u];
		}
		if (mult_up > max_up ) max_up = mult_up;

		printf("\n");
		mult_diag_r = input[i];
		printf("\\ diag\t%d ", mult_diag_r);
		int lc = 1;
		for (int dr = i + 20; dr <= (i + (19 * 4)); dr += 20) 
		{
			if (i > (16 * row) ) break;
			printf("%d ", input[dr + lc]);
			mult_diag_r *= input[dr];
			lc++;
		}
		if (mult_diag_r > max_diag_r) max_diag_r = mult_diag_r;
		printf("\n");

//		printf("\n");
//		printf("/ diag\t%d ", idx);
//		int lc = 1;
//		for (int dr = i + 20; dr <= (i + (19 * 4)); dr += 20) 
//		{
//			if (i > (16 * row) ) break;
//			printf("%d ", input[dr + lc]);
//			lc++;
//		}
//		printf("\n");


		if ((i + 1) % 20 == 0) row++;

		mult_left = 0;
		mult_right = 0;
		mult_up = 0;
		mult_down = 0;
		mult_diag_r = 0;
	}


	printf("-> %ld\n <- %ld\n up %ld \n down %ld \n diag %ld \n", max_left, max_right, max_up, max_down, max_diag_r);



	return 0;
}

