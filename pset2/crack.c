/**************************
Passwords Et Cetera |dictionary crack DES encryption
CS50/2013/hacker2

Crack these passwords, each of which has been encrypted with C’s DES-based (not MD5-based) crypt function. 
Assume that users' passwords, as plaintext, are no longer than eight characters long.
jharvard@appliance (~/Dropbox/hacker2): ./crack 50yoN9fp966dU
crimson

定义函数
char * crypt (const char *key,const char * salt);
函数说明
crypt是个密码加密函数，它是基于Data Encryption Standard(DES)演算法。crypt只适用于密码的使用，不适合用于资料加密。
crypt()将参数key所指的字符串加以加密，key字符串长度仅取前8个字符，超过此长度的字符没有意义。
参数salt为两个字符组成的字符串，由a-z、A-Z、0-9，“.”和“/”所组成，用来决定使用4096 
（a-z、A-Z、0-9，“.”和“/”共64个字符，64的平方为4096）种不同内建表格的哪一个。定义函数
char * crypt (const char *key,const char50yoN9fp966dU * salt);
函数说明
crypt是个密码加密函数，它是基于Data Encryption Standard(DES)演算法。crypt只适用于密码的使用，不适合用于资料加密。
crypt()将参数key所指的字符串加以加密，key字符串长度仅取前8个字符，超过此长度的字符没有意义。参数salt为两个字符组成的字符串，由a-z、A-Z、0-9，“.”和“/”所组成，用来决定使用4096 （a-z、A-Z、0-9，“.”和“/”共64个字符，64的平方为4096）种不同内建表格的哪一个。函数执行成功后会返回指向编码过的字符串指针，参数key 所指的字符串不会有所更动。编码过的字符串长度为13 个字符，前两个字符为参数salt代表的字符串。
返回值
返回一个指向以NULL结尾的密码字符串。
注意编译时要在末尾添加-lcrypt选项。
函数执行成功后会返回指向编码过的字符串指针，参数key 所指的字符串不会有所更动。编码过的字符串长度为13 个字符，前两个字符为参数salt代表的字符串。
返回值
返回一个指向以NULL结尾的密码字符串。
注意编译时要在末尾添加-lcrypt选项。
**************************/
#define _X_OPENSOURCE // char *crypt(const char *key, const char *salt);
#define PASS_MAX  8

#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <crypt.h> // if no,implicit declaration of function 'crypt' is invalid in C99
#include <string.h>

int main(int argc, char *argv[])
{
    // get user commond line
    if (argc != 2)
    {
        printf("Wrong!");
        return 1;
    }
    // from user input get the salt
    // printf("%s",crypt("crimson","50"));
    char salt[2];
    for (int i = 0;i < 2;i++) // salt is the first and second
    {
        salt[i] = argv[1][i];
    }
    //open the file
    FILE *fp = NULL;
    if ((fp = fopen("linux.words","r")) == NULL)
    {
        printf("cannot open this file\n");
        return -1;
    }
    // crack the ciphertexts by dictionary

    //char key [9];// donot forget '\0',C’s DES-based plaintext, are no longer than eight characters long
    //while (fgets(key,9,fp) != NULL)
    //{
    //    if (strcmp(crypt(key,salt),argv[1]) == 0)
    //    {
    //        printf("%s",key);
    //        fclose(fp);
    //        return 0;
    //    }      
    //}
    //apparently there were two problems: 
    //a)fgets adds a NULL byte at the end which changes the encryption, I fixed it by adding char* temp which takes the values before passing them to pass
    //b) I think this is something the txt file did.. I switched to the linux dictionary and the problem was solved
    //printf("%s\n",crypt("caesar","50"));
    while (!feof(fp))
    {
        char temp[PASS_MAX+2];
        fgets (temp,PASS_MAX+2, fp);
        int n = strlen(temp);
        char pass[PASS_MAX+2] = {};
        //remove NULL at end
        for (int i=0; i < n-1 ; i++)
            pass[i] = (char) temp[i];
        //encrypt
        string crypt_pass = crypt(pass, salt);
        if(!strcmp(crypt_pass, argv[1]))
        {
            printf("%s\n", pass);
            fclose(fp);
            return 0;
        }
    }
    // print error and close the file
    printf("cannot crack\n");
    fclose(fp);
    return 0;
}
