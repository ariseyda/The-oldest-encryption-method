#include<stdio.h>
#include<string.h>
#define size 100

//Encode the program written on the screen by encrypting the sentence until the dot (.) 
//Is typed on the keyboard. As an encryption basis, one of the oldest encryption methods, “shifting each letter by a certain amount”, has been taken as basis. 
//According to this; The amount of translation, which is entered from the keyboard, will be replaced by 3 letters from each letter when 3 is selected. 
//In other words, all A's are denoted by D, and all K's are denoted by the letter N. 
//When translated, the letters that pass the last letter are returned to the beginning and continue from there. 
//(It is assumed that there are no Turkish characters and numbers in the text to be entered)

int main(){
	
	char letters[26][2]={{'a','A'},{'b','B'},{'c','C'},{'d','D'},{'e','E'},{'f','F'},{'g','G'},{'h','H'},{'i','I'},{'j','J'},{'k','K'},{'l','L'},{'m','M'},{'n','N'},{'o','O'},
	{'p','P'},{'q','Q'},{'r','R'},{'s','S'},{'t','T'},{'u','U'},{'v','V'},{'w','W'},{'x','X'},{'y','Y'},{'z','Z'}};
	
	char sentence[size]="";
	char words[size]="";
	int x;
	printf("How long should the letters be shifted?:");
	scanf("%d",&x);
	printf("Enter a sentence:");
	
	while(1){
		
		gets(words);
		if(strcmp(words,".")==0){
			strcat(sentence,".");
			break;
		}
		else if(strcmp(words," ")==0){
			strcat(sentence," ");
		}
		else{
			strcat(sentence,words);
		}
		
	}
	
	printf("Message:%s",sentence);
	
	int len=strlen(sentence);
	
	int j,k,l;
	for(j=0;j<len;j++){
	  for(k=0;k<26;k++){
		for(l=0;l<2;l++){
				
		   while(sentence[j]==letters[k][l]){
					
			if(k<26-x){
						
			 sentence[j]=letters[k+x][l];
			 j++;
						
						
		         }
					
			 else{
						
			   int a=25-k;
			   sentence[j]=letters[x-a-1][l];
			   j++;
					    	
			  }
			   
			k=-1;
			break;	
		             }
				
			}
		}
		
	}	
	
	printf("\nEncrypted message:%s",sentence);
	

	
	return 0;
}


