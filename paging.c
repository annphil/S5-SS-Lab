//Pgm to implement paging. 
// Takes page requests for each process, checks if requested pages are free, if not, it's not allocated.  
#include<stdio.h>

void main(){
	int ms, ps, nop, rempages, npr, i, j, pt[50][50], nf, f[50];
	printf("Enter memory size: ");
	scanf("%d", &ms);	
	printf("Enter page size: ");
	scanf("%d", &ps);
	nop = ms/ps;
	rempages = nop;
	printf("No of pages available in memory: %d", nop);
	//Initialising filled frames array with 0
	for(i=0; i<nop; i++){
		f[i]=0;	
	}
	
	printf("\nEnter no. of processes: ");
	scanf("%d", &npr);
	for(i=0; i<npr; i++){
		int flag = 0;
		printf("Enter no. of pages required for process %d: ", i+1);
		scanf("%d", &nf);
		if(nf < rempages){
			printf("Enter page table values(btwn 0 and %d): ", nop);
			for(j=0; j<nf; j++){
				scanf("%d", &pt[i][j]);	
			}
			//Checking if frames requested are free 
			for(j=0; j<nf; j++){
				if(f[pt[i][j]] == 1){
					flag = 1;
					break;
				}
			}
			if(flag==0){
				for(j=0; j<nf; j++){
					f[pt[i][j]] = 1;
				}
				rempages -= nf;
				printf("Frames allocated\n");
			}
			else
				printf("Frames cannot be allocated\n");
		}
		else
			printf("No of page requests is more than what's available\n");
	}
}
