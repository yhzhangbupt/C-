%{
	#include <stdio.h>
	#include <stdlib.h> 
        #include <string.h>
	int count = 0;
        int rowcount = 1;
        int charcount = 0;
	int reservedWordcount = 0;
	int operatorcount = 0;
	int delimitercount = 0;
	int constantcount = 0;
	int strconscount = 0;
	int charconscount = 0;
	int identfiercount = 0;
	int illegleIdentifiercount = 0;


%} 
 
delim [" "\t] 
whitespace {delim}+ 
operator \+|\-|\*|\/|\%|\+=|\-=|\>=|\<=|#|=|\<\<|\>\>|&|\||\^|\+\+|\-\-|!|!=|\>|\<|&&
reservedWord int|long|short|float|double|char|unsigned|signed|const|void|volatile|enum|struct|union|if|else|goto|switch|case|do|while|for|continue|break|return|default|typedef|auto|register|extern|static|sizeof
delimiter [,\.;\(\)\{\}\[\]]
constant ([0-9])+
strcons \"([A-Za-z]|[0-9])*\"
charcons '[A-Za-z]'
illegleIdentifier [0-9]([A-Za-z]|[0-9])*[A-Za-z]([A-Za-z]|[0-9])*
identfier [A-Za-z]([A-Za-z]|[0-9])*
rowannotation \/\/([A-Za-z]|[0-9]|{delim}|{operator}|{reservedWord}|{delimiter}|'|\")*\n
annotation \/\*([A-Za-z]|[0-9]|{delim}|{reservedWord}|{delimiter}|'|\"|\n)*\*\/
%%
{reservedWord} {reservedWordcount++;charcount+=strlen(yytext);printf("<reserved_word,'%s'>\n",yytext);}
{operator} { operatorcount++;charcount+=strlen(yytext);printf("<oprator,'%s'>\n",yytext); }
{delimiter} {delimitercount++;charcount+=strlen(yytext);printf("<delimiter,'%s'>\n",yytext);}
{constant} {constantcount++;charcount+=strlen(yytext);printf("<constant,'%s'>\n",yytext);}
{strcons} {strconscount++;charcount+=strlen(yytext);printf("<strcons,'%s'>\n",yytext);}
{charcons} {charconscount++;charcount+=strlen(yytext);printf("<charcons,'%s'>\n",yytext);}
{rowannotation} {rowcount++;} 
{annotation} {rowcount=rowcount+rowc(yytext);} 
{identfier} {identfiercount++;charcount+=strlen(yytext);printf("<identfier,'%s'>\n",yytext);} 
{illegleIdentifier} {illegleIdentifiercount++;charcount+=strlen(yytext);printf("error\trow%d<error,'%s'>\n",rowcount,yytext);} 
{whitespace} { /* do    nothing*/ } 
\n  {rowcount++;}


%% 
void main() 
{
    printf("THE LEXICAL ANALYSIS GENERATOR LEX:\n");
	printf("1: reserved_word\n");
	printf("2: oprator\n");
	printf("3: delimiter\n");
	printf("4: constant\n");
	printf("5: identfier\n");
        printf("6: strcons\n");
        printf("7: charcons\n");
        printf("8: error\n");
	printf("\n");
	yyin=fopen("test.txt","r"); 
    	yylex(); /* start the analysis*/ 
	fclose(yyin);
        printf("row count\t%d\n",rowcount);
        printf("char count\t%d\n",charcount);
count=reservedWordcount+operatorcount+delimitercount+constantcount+strconscount+charconscount+identfiercount+illegleIdentifiercount;
        printf("word count\t%d\n",count);
        printf("reservedWord count\t%d\n",reservedWordcount);
        printf("operator count\t%d\n",operatorcount);
        printf("delimiter count\t%d\n",delimitercount);
        printf("constant count\t%d\n",constantcount);
        printf("strcons count\t%d\n",strconscount);
        printf("charcons count\t%d\n",charconscount);
        printf("identfier count\t%d\n",identfiercount);
        printf("error count\t%d\n",illegleIdentifiercount);
        
	system("PAUSE");/*暂停停,  使DOS窗口停住*/
} 
 int yywrap() 
 { 
 	return 1; 
 }
//annotation count \n
int rowc(char* s)
{
    char *src="\n";
    char *ptr=src, *p=s;    //定义两个指针 
    char *ptr2=src+strlen(src), *prev=NULL;    //ptr2为src的末位置指针 
    int len=strlen(s), n=0;        //子串的长度和计数器 
    for(;*ptr;ptr++)    //循环整个串 
    {
        if(ptr2-ptr<len)    //如果一开始子串就大于src,则退出 
            break;
        for(prev=ptr;*prev==*p;prev++,p++)    //寻找第一个相等的位置,然后从此位置开始匹配子串 
        {
            if(*(p+1)==0||*(p+1)==10)    //如果已经到了子串的末尾 
            {
                n++;    //自增 
                p=s;    //重新指向子串 
                break;//退出 
            }
        }
    }
    return n;
}