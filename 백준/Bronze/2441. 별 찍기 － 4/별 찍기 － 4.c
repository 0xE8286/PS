int main(){
	int N;
	int i, j;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i > j)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}