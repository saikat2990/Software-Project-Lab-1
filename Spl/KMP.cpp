#include<bits/stdc++.h>

using namespace std;
    
       
       
void kmp(string str,unsigned char arr[],unsigned int length){   

          /*unsigned char arr[2048] = "....www.facebook.com........youtube.com..........E..>.{@.@.I1...........5.*.=U.............";*/
     FILE *fp;     
    fp = fopen("ans.txt","a");
    
    unsigned int f [20];
    unsigned int k=0,q;
    int len = str.length();
    
    unsigned char ch[len+1];
    for(int i=0;i<len;i++)ch[i]=str[i];
    
    f[0]=0;
    for(q=1;q<len;q++){
    
        while(k>0&&str[q]!=str[k])
            k = f[k-1];
        if(str[q]==str[k])
            k=k+1;
        f[q]=k;
        //cout<<k<<endl;
    }
            
        //unsigned char strFb[20] = "facebook.com";
        
            //unsigned int length=56;
            //unsigned int k=0,q;
            int t=0;
            //f[0]=0;
            k=0;
            for(q=1;q<length;q++){
            
                while(k>0&&arr[q]!=str[k])
                    k = f[k];
                if(arr[q]==str[k])
                    k=k+1;
                if(k==len){
                    //cout<<str<<" found at index "<<q-12<<endl;
                    printf("%s found at index %d\n",ch,q-len);
                    t=1;
                    break;
                }


            }
              
}

int kmpsearch(unsigned char pkt[],int frameNum,int length){
 /*int main(){ 
       
          unsigned char pkt[2048] = "....www.facebook.com........youtube.com..........E..>.{www.facebook.com...........5.*.=U.............";
          int length = 56;*/
          
      unsigned char arr[2048];
          
      for(int q=0;q<length;q++){ 
      
          unsigned int temp = pkt[q];
          if(isprint(temp))arr[q]=(unsigned char)pkt[q]&0xff;
          else arr[q] = '.';
          //sif(q%16==0)printf("\n");
          
      }
                
       kmp("facebook.com",arr,length);
       kmp("youtube.com",arr,length);

               
}
