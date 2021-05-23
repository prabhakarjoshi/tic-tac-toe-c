#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<Windows.h>

char A[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};char a[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char a1[]={'1','2','3','4','5','6','7','8','9','0'};char b[][3]={{"12"},{"13"},{"14"},{"15"},"16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32"};char c[]={'!','`','~','@','#','$','%','^','&','*','(',')','-','_','=','+',92, 124,93,123,91,125,39,34,';',':','/','?','.','>',',','<'};
int random=3;
int prev,cnt=0;

int form_rannum(){
     
     
     time_t second=time(NULL);
     if(second==prev)
     second++;
     prev=second;
     random*=second*second;
     random%=10000;
     if(random<0)   random*=-1;
     if(random<100 ||random==0) random+=100;
     return random;
}

char ran_upp(){
    int j=form_rannum();

    return A[j%26];
}
char ran_low(){
    int j=form_rannum();
    return a[j%26];
}
char ran_num(){
    int j=form_rannum();
    return a1[j%10];
}
char ran_spe(){

    int j=form_rannum();
    return c[j%32];
}
char ran_fun(){
    int j=form_rannum();
    switch (j%4)
    {
    case 0:
        return ran_num();
        break;
    case 1:
        return ran_low();
        break;
    case 2:
        return ran_upp();
        break;

    case 3:
        return ran_spe();
        break;

    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{

    here:;
    cnt++;
//finding length

    int i,j;
    i=form_rannum()%21;
    int len=atoi(b[i]);
    char* pass=(char*)malloc(len*sizeof(char)+1);


    //minimum requirements

    pass[0]=ran_low();
    pass[1]=ran_num();
    pass[2]=ran_spe();
    pass[3]=ran_low();
    pass[4]=ran_upp();
    pass[len-1]=ran_upp();
    pass[len]=0;
    for(i=5;i<len-1;i++)
        pass[i]=ran_fun();
    

    //shuffling
    
    
    fflush(stdout);
    for(int i=len-2;i>=3;i--){
         j=form_rannum()%(i+1);
        
        if(j==0) j++;
        int t=pass[i];
        pass[i]=pass[j];
        pass[j]=t;
    }
    // puts(pass);
    

int id;
if(cnt==1)
     id=MessageBox(NULL,"click button to generate password" , TEXT("Random Password Gnerator"), MB_OK | MB_SYSTEMMODAL);
else
     id=MessageBox(NULL, TEXT(pass), TEXT("Random Password Gnerator"), MB_CANCELTRYCONTINUE | MB_ICONEXCLAMATION | MB_DEFBUTTON3 | MB_SYSTEMMODAL);

free(pass);

switch (id)
    {
    case IDOK:
        goto here;
        break;    
    case IDCANCEL:
        // Nothinig to do
        break;

    case IDTRYAGAIN:
        // starting again
        goto here;
        break;

    case IDCONTINUE:
    ;;
   
   const char* output = pass;
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    id=MessageBox(NULL,"password copied to clipboard" , TEXT("Random Password Gnerator"), MB_OK | MB_SYSTEMMODAL);
        break;
    }


return 0;

}