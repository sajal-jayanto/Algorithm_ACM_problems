#include <stdio.h>
int decimal_binary();
int decimal_octal();
int decimal_hexadecimal();
int binary_decimal();
int binary_octal();
int binary_hexadecimal();
int octal_decimal();
int octal_binary();
int octal_hexadecimal();
int hexadecimal_decimal();
int hexadecimal_octal();
int hexadecimal_binary();
int main()
{
    int  n;
    printf("                -------------------------------------\n");
    printf("                    ---WELCOME TO NUMBER SYSTEM--\n");
    printf("                -------------------------------------\n");
    for(;;){
            printf("CHOOS ANY OPSATION--\n");
            printf("\t\t   1-> FOR DECIMAL TO BINARY.\n");
            printf("\t\t   2-> FOR DECIMAL TO OCTAL.\n");
            printf("\t\t   3-> FOR DECIMAL TO HEXADECIMAL.\n");
            printf("\t\t   4-> FOR OCTAL TO DECIMAL.\n");
            printf("\t\t   5-> FOR OCTAL TO BINARY.\n");
            printf("\t\t   6-> FOR OCTAL TO HEXADECIMAL.\n");
            printf("\t\t   7-> FOR BINARY TO DECIMAL.\n");
            printf("\t\t   8-> FOR BINARY TO OCTAL.\n");
            printf("\t\t   9-> FOR BINARY TO HEXADECIMAL.\n");
            printf("\t\t  10-> FOR HEXADECIMAL TO DECIMAL.\n");
            printf("\t\t  11-> FOR HEXADECIMAL TO OCTAL.\n");
            printf("\t\t  12-> FOR HEXADECIMAL TO BINRY.\n");
            printf("\t\t  13-> FOR EXIT.\n");
            printf("\nYOU CHOOS OPSATION:");
            scanf("%d",&n);
            if(n==1){
                decimal_binary();
            }
            if(n==2){
                decimal_octal();
            }
            if(n==3){
                decimal_hexadecimal();
            }
            if(n==4){
                octal_decimal();
            }
            if(n==5){
                octal_binary();
            }
            if(n==6){
                octal_hexadecimal();
            }
            if(n==7){
                binary_decimal();
            }
            if(n==8){
                binary_octal();
            }
            if(n==9){
                binary_hexadecimal();
            }
            if(n==10){
                hexadecimal_decimal();
            }
            if(n==11){
                hexadecimal_octal();
            }
            if(n==12){
                hexadecimal_binary();
            }
            if(n==13){
                break;
            }
            if(n>=14){
                printf("\n\n\t\tSORRY YOU ENTER AN INVELID OPSITION.\n\n");
            }

    }
    return 0;

}
int decimal_octal()
{
	int a[100],num,i=0,lon=0;
	printf("\n\t\tEnter decimal number:");
        scanf("%d",&num);
	printf("\n\t\tThe octal of %d is=",num);

	while(num){
        a[i]=num%8;
        num=num/8;
        i++;
        lon++;
	}

        for(i=lon-1;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n\n");
    return 0;
}
int octal_decimal()
{

    int octalnum,decinum=0,rembar=0,j=1,n;
    printf("\n\n\t\tEnter octal number:");
        scanf("%d",&octalnum);
        n=octalnum;

    while(octalnum){
        rembar=octalnum%10;
        decinum+=rembar*j;
        j=j*8;
        octalnum/=10;
    }
    printf("\n\t\tThe decimal of %d is=%d",n,decinum);

    printf("\n\n");

    return 0;


}
int binary_octal()
{
    long int binarynum,decinum=0,rembar=0,j=1,n;
    int a[100],num,i=0,lon=0;
    printf("\n\n\t\tEnter binary number:");
        scanf("%ld",&binarynum);
    n=binarynum;
    printf("\n\t\tThe octal of %d is=",binarynum);

    while(binarynum){
        rembar=binarynum%10;
        decinum+=rembar*j;
        j=j*2;
        binarynum/=10;
    }
    num=decinum;

	while(num){
        a[i]=num%8;
        num=num/8;
        i++;
        lon++;
	}
        for(i=lon-1;i>=0;i--){
            printf("%d",a[i]);
        }
    printf("\n\n");
     return 0;
}
int octal_binary()
{
    int octalnum,decinum=0,rembar=0,j=1,n;
    int a[100],num,i=0,lon=0;
    printf("\n\n\t\tEnter octal number:");
    scanf("%d",&octalnum);

    while(octalnum){
        rembar=octalnum%10;
        decinum+=rembar*j;
        j=j*8;
        octalnum/=10;
    }
    num=decinum;
    printf("\n\t\tThe binary of %d is=",num);

    while(num){
        a[i]=num%2;
        num=num/2;
        i++;
        lon++;
	}
        for(i=lon-1;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n\n");
    return 0;

}
int decimal_binary()
{
    int a[100],num,i=0,lon=0;
	printf("\n\n\t\tEnter decimal number:");
        scanf("%d",&num);
	printf("\n\t\tThe binary of %d is=",num);

	while(num){
        a[i]=num%2;
        num=num/2;
        i++;
        lon++;
    }
        for(i=lon-1;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n\n");
	return 0;

}
int binary_decimal()
{

    long int binarynum,decinum=0,rembar=0,j=1,n;
    printf("\n\n\t\tEnter binary number:");
    scanf("%ld",&binarynum);
    n=binarynum;

    while(binarynum){
        rembar=binarynum%10;
        decinum+=rembar*j;
        j=j*2;
        binarynum/=10;
    }
    printf("\n\t\tThe decimal of %ld is=%ld",n,decinum);

    printf("\n\n");

    return 0;


}
int decimal_hexadecimal()
{
    int a[100],num,i=0,lon=0;
	printf("\n\n\t\tEnter decimal number:");
        scanf("%d",&num);
    printf("\n\t\tThe hexadecimal of %d is=",num);

	while(num){
        a[i]=num%16;
        num=num/16;
        i++;
        lon++;
	}
        for(i=lon-1;i>=0;i--){
            if(a[i]==10)
                printf("A");
            if(a[i]==11)
                printf("B");
            if(a[i]==12)
                printf("C");
            if(a[i]==13)
                printf("D");
            if(a[i]==14)
                printf("E");
            if(a[i]==15)
                printf("F");
            if(a[i]!=10&&a[i]!=11&&
               a[i]!=12&&a[i]!=13&&
               a[i]!=14&&a[i]!=15){
            printf("%d",a[i]);
            }
        }
        printf("\n\n");
    return 0;

}
int octal_hexadecimal()
{
    int octalnum,decinum=0,rembar=0,j=1;
    int a[100],num,i=0,lon=0;
    printf("\n\n\t\tEnter octal number:");
        scanf("%d",&octalnum);
    printf("\n\t\tThe hexadecimal of %d is =",octalnum);

    while(octalnum){
        rembar=octalnum%10;
        decinum+=rembar*j;
        j=j*8;
        octalnum/=10;
    }
    num=decinum;

    while(num){
        a[i]=num%16;
        num=num/16;
        i++;
        lon++;
	}
        for(i=lon-1;i>=0;i--){
            if(a[i]==10)
                printf("A");
            if(a[i]==11)
                printf("B");
            if(a[i]==12)
                printf("C");
            if(a[i]==13)
                printf("D");
            if(a[i]==14)
                printf("E");
            if(a[i]==15)
                printf("F");
            if(a[i]!=10&&a[i]!=11&&
               a[i]!=12&&a[i]!=13&&
               a[i]!=14&&a[i]!=15){
            printf("%d",a[i]);
            }
        }
        printf("\n\n");
    return 0;

}
int binary_hexadecimal()
{
    long int binarynum,decinum=0,rembar=0,j=1;
    int a[100],num,i=0,lon=0;
    printf("\n\n\t\tEnter binary number:");
        scanf("%ld",&binarynum);
    printf("\n\t\tThe hexadecimal of %ld is=",binarynum);

    while(binarynum){
        rembar=binarynum%10;
        decinum+=rembar*j;
        j=j*2;
        binarynum/=10;
    }
    num=decinum;

    while(num){
        a[i]=num%16;
        num=num/16;
        i++;
        lon++;
	}
        for(i=lon-1;i>=0;i--){
            if(a[i]==10)
                printf("A");
            if(a[i]==11)
                printf("B");
            if(a[i]==12)
                printf("C");
            if(a[i]==13)
                printf("D");
            if(a[i]==14)
                printf("E");
            if(a[i]==15)
                printf("F");
            if(a[i]!=10&&a[i]!=11&&
               a[i]!=12&&a[i]!=13&&
               a[i]!=14&&a[i]!=15){
                printf("%d",a[i]);
               }
        }
        printf("\n\n");
    return 0;

        }
int hexadecimal_decimal()
{
    long int decinum;
    printf("\n\n\t\tEnter hexadecimal number:");
    scanf("%X",&decinum);
    printf("\n\t\tThe decimal of %x is=%d",decinum,decinum);
    printf("\n\n");
    return 0;

}
int hexadecimal_binary()
{
    int a[100],num,i=0,lon=0;
	printf("\n\n\t\tEnter hexadecimal number:");
        scanf("%X",&num);
	printf("\n\t\tThe binary of %X is=",num);

	while(num){
        a[i]=num%2;
        num=num/2;
        i++;
        lon++;
	}

        for(i=lon-1;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n\n");
    return 0;
}
int hexadecimal_octal()
{
    int a[100],num,i=0,lon=0;
	printf("\n\n\t\tEnter hexadecimal number:");
        scanf("%X",&num);
	printf("\n\t\tThe octal of %X is=",num);

	while(num){
        a[i]=num%8;
        num=num/8;
        i++;
        lon++;
	}

        for(i=lon-1;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n\n");
    return 0;

}
