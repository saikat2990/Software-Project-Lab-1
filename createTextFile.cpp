#include<bits/stdc++.h>
#include<string>
#include"headerFormat.cpp"


using namespace std;



string funstring(int num){

    stringstream iss;
    iss<<num;

    string str;
    iss>>str;

    return str;
}


void createText(){

    int i,cn=0;
    FILE *fp;
    fp = fopen("sai.pcap","rb");

    struct GlobalHeader gH;
    struct packetHeader hx;

    fread(&gH,sizeof(struct GlobalHeader),1,fp);
    int coun=0;
    while(!feof(fp)){
            coun++;

            unsigned int byteCount=0;
            fread(&hx,sizeof(struct packetHeader),1,fp);

            //printf("%.02x\n",gH.GHeader[0]&0xff);

            for( i=0;i<4;i++){

                   // printf(".....%.02x  \n",hx.LengthOfThePacket[i]&0xff);
                    //printf(" -->%d  \n",(int)hx.LengthOfThePacket[i]);
                    //printf("   %d    \n",byteCount);

                    //byteCount = byteCount + (int)hx.LengthOfThePacket[i];
           }

            //printf(" %d is my packetSize  \n",(int)hx.LengthOfThePacket);

               byteCount=hx.LengthOfThePacket[0];
               byteCount=byteCount<<8;
               byteCount=byteCount|hx.LengthOfThePacket[1];
               byteCount=byteCount<<8;
               byteCount=byteCount|hx.LengthOfThePacket[2];
               byteCount=byteCount<<8;
               byteCount=byteCount|hx.LengthOfThePacket[3];

               //printf("%d\n",byteCount);

            unsigned char packet[byteCount],ch;

            //ofstream ofile;
            //ofile.open(cn+".txt");

            string str ;

            str = funstring(cn);
            cout<<str<<endl;

            FILE *ofile;
            str += ".txt";
            ofile = fopen(str.c_str(),"w");

            //char chr='0x';

            unsigned int spa =0;
            unsigned char spaces=' ';
            unsigned char en='\n';
            unsigned char gar='.';
            unsigned char val[20];

            fprintf(ofile,"%d ", byteCount);
            fprintf(ofile,"%c", en);
            int temp = byteCount;

            for(i=0;i<byteCount;i++){
                 temp--;
                fread(&ch,sizeof(ch),1,fp);
                printf("%0.2x ",ch&0xff);
                val[spa] =(char)ch;
                spa++;

                fprintf(ofile,"%0.02x ", ch&0xff);
                if(spa==8){fprintf(ofile,"%c", spaces); fprintf(ofile,"%c", spaces);}
                else if(spa==16){

                    fprintf(ofile,"%c", spaces);
                    fprintf(ofile,"%c", spaces);
                    fprintf(ofile,"%c", spaces);

                    for(int j=0;j<16;j++){
                        if(!isprint((char)val[j]))fprintf(ofile,"%c", gar);
                        else  fprintf(ofile,"%c", (char)val[j]);

                    }
                    fprintf(ofile,"%c", en);
                    cout<<endl;
                    spa=0;
                   // temp=temp-16;
                }
                else if(temp==0 && spa<16){

                    for(int k=spa;k<=16;k++)
                        fprintf(ofile,"%c", spaces),fprintf(ofile,"%c", spaces),fprintf(ofile,"%c", spaces);;


                    //fprintf(ofile,"%c", spaces);
                    //fprintf(ofile,"%c", spaces);
                    fprintf(ofile,"%c", spaces);

                    for(int j=0;j<spa;j++){
                        if(!isprint((char)val[j]))fprintf(ofile,"%c", gar);
                        else  fprintf(ofile,"%c", (char)val[j]);

                    }
                    fprintf(ofile,"%c", en);
                    cout<<endl;
                    spa=0;
                }


            }

            cn++;

    }

    cout<<cn<<endl;
}
