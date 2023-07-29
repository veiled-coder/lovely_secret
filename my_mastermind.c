#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
// #include <cstdlib.h>

int getUserInput(int ac, char *argv[]) {
    int wellPlacedValues = 0;
    int misPlacedValues = 0;
    bool isPresent = false;
    bool wrongInput=false;
    char playerInputString[5];
    char secretCode[5];
  
    
    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    // check for command line argument -c
    if (ac > 2 && strcmp(argv[1], "-c") == 0) {
        strcpy(secretCode, argv[2]);
    }
    //if no command-line argument,genrate random number
    else{
        bool used[9]={false};
        int my_rand[4];
        srand(time(0));
        for (int r=0; r<4;r++){
            int num=rand()%(9);//generate random number between 0-8
            while(used[num]){//continue running until used[num] is false
                num=rand()%(9);
            }
            my_rand[r]=num;
            used[num]=true;
        
            
        }
        sprintf(secretCode, "%d%d%d%d", my_rand[0], my_rand[1], my_rand[2], my_rand[3]);
       }

       //for 10 rounds
    for (int t = 0; t < 10; t++) {
        printf("\nRound %d\n", t);
        // get the user input  from the terminal for each round
        int bytes_read = read(STDIN_FILENO, playerInputString, 5); // read all 4 characters plus null terminator
        playerInputString[bytes_read - 1] = '\0'; // set the last character to null terminator
        
        if(bytes_read==0){//if CTRL+D pressed,E0F is encountered,bytes_read will be 0 (end the game)
            exit(0);
        }

        misPlacedValues = 0;
        wellPlacedValues = 0;
        wrongInput=false;
        
        //loop through player's guess input and compare each value with secretcode
        for (int i = 0; i < 4; i++) {
           
            if(playerInputString[i]>=48 && playerInputString[i]<=56){//if player value is between 0-8
                
            
            isPresent = false;
            for (int j = 0; j < 4; j++) {
                if (playerInputString[i] == secretCode[j]) {
                    isPresent = true;
                }
            }

            if (isPresent && playerInputString[i] == secretCode[i]) {
                wellPlacedValues++;
            }

            if (isPresent && playerInputString[i] != secretCode[i]) {
                misPlacedValues++;
            }
            }
            else{//if player value is not between 0-8
            wrongInput=true;    
            }
            
        }//end of loop

           if (!wrongInput){
        
             if(wellPlacedValues==4){
             printf("Congratz! You did it!\n");
             exit(0);
             }
             else{
             printf("Well placed pieces: %d\n", wellPlacedValues);
             printf("Misplaced pieces: %d\n", misPlacedValues);
             }
           }
           else{
           printf("Wrong input!\n");
           }


           //check  the end of the rounds
           if(t==9){
           printf("\nsecret code is %s\n",secretCode);

           }
}
   
 return 0;

}
   


int main(int ac, char *argv[]) {
    getUserInput(ac, argv);
    return 0;
}
