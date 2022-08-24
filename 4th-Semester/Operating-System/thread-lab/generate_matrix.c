int main(){

	for(int i=0; i<9; i++){
		printf("{");
		for(int j=0; j<9; j++){
			if(j==8) printf("%d",i+j);
			else printf("%d,",i*j+1);
		}
		printf("},\n");;
	}
return 0;
}
