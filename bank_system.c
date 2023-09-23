#include <stdio.h>
#include <string.h>

struct userD {
    char username[50];
    char pnumber[15];
    char adharnum[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
    char accNo[100];
};

struct transferM {
    char senderId[50];
    char receiverId[50];
    int amount;
};

int accountDetails(char *acc, char *fname, char *pin) {
    struct userD u1;
    printf("\n\n------CREATE ACCOUNT-------");
    
    printf("\nFIRST NAME:");
    scanf("%s", fname);
    
    printf("\nLAST NAME:");
    scanf("%s", u1.lname);
    
    printf("\nFATHER's NAME:");
    scanf("%s", u1.fathname);
    
    printf("\nMOTHER's NAME:");
    scanf("%s", u1.mothname);
    
    printf("\nADDRESS:");
    scanf("%s", u1.address);
    
    printf("\nACCOUNT TYPE:");
    scanf("%s", u1.typeaccount);
    
    printf("\nAADHAR NUMBER (12 digits):");
    scanf("%s", u1.adharnum);
    
    printf("\nPHONE NUMBER (10 digits):");
    scanf("%s", u1.pnumber);
    
    printf("\nUSERNAME:");
    scanf("%s", u1.username);
    
    printf("\nHooray! Your account has been created!\n");
    strcpy(acc, u1.adharnum);
    printf("ACC no.: ac%s\n", acc);
    printf("Enter new pin: ");
    scanf("%s", pin);
    
    printf("You're all set!\n\n");
}

int ATMDetails(char *acc, char *fname) {
    struct userD u1;
    printf("\n\n--------Your ATM Details-------\n");
    printf("Bank Account Holder: %s\n", fname);
    printf("Bank Acc. no: ac%s\n", acc);
    printf("IFSC Code: CIU000004\n");
    printf("Expiry Date: 12/11/2030\n\n");
}

int depositMoney(float *amt) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if(amount <= 0) {
        printf("Enter a positive number!");
    } else {
        *amt += amount;
        printf("You have successfully deposited Rs.%.2f\n", amount);
    }
}

int transferMoney(char *pin, float *amt) {
    char racc[40], cpin[10];
    int amount;
    printf("Enter Acc. no: ");
    scanf("%s", racc);
    printf("Enter pin: ");
    scanf("%s", cpin);
    
    if(strcmp(cpin, pin) == 0) {
        printf("Enter Amount: ");
        scanf("%d", &amount);
        
        if(amount <= 0) {
            printf("Enter a positive number!\n");
        } else if (amount > *amt) {
            printf("Insufficient Balance!\n");
        } else {
            *amt -= amount;
            printf("%d Money Transferred :)\n", amount);
            printf("Remaining balance: %.2f\n", *amt);
        }
        
    } else {
        printf("Wrong Pin, Try again\n");
    }
}

int checkBalance(float *amt, char *pin) {
    char cpin[10];
    printf("Enter pin: ");
    scanf("%s", cpin);
    
    if(strcmp(cpin, pin) == 0) {
        printf("Balance: %.2f\n", *amt);
    } else {
        printf("Wrong Pin, Try again\n");
    }
}

int main()
{
    int ch;
    float amt = 0.0;
    char acc[50], fname[50], pin[10];
    printf("Welcome to Bank of Swiss!\n");
    
    do {
        printf("\n\n1. Create Account\n2. ATM Details\n3. Deposit\n4. Transfer Money\n5. Check Balance\n6. Exit\n\n");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                accountDetails(acc, fname, pin);
                break;
            case 2: 
                ATMDetails(acc, fname);
                break;
            case 3:
                depositMoney(&amt);
                break;
            case 4:
                transferMoney(pin, &amt);
                break;
            case 5:
                checkBalance(&amt, pin);
                break;
            case 6:
                printf("\nHappy Banking :)\n");
                break;
            default: 
                printf("Invalid Option!\n");
                break;
        }
        
    } while(ch != 6);

    return 0;
}


