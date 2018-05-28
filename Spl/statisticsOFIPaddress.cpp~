#include<bits/stdc++.h>
#include<stdlib.h>


using namespace std;

string ss(int num){
    
    string str;
    stringstream iss;
    iss<<num;
    iss>>str;
    return str;
    
}

struct iPa{
    
    string sourceIp;
    string destinationIP;
    int count;
    
};

iPa stat[10000];

struct compare{
    
    bool operator()(const iPa& l,const iPa& r){
        return l.count<r.count;
    }
    
};

priority_queue<iPa ,vector<iPa>, compare >q;

int number;

int staticsOFIPadress(unsigned char pkt[],int length,int no,int packetNum){
    
    
    bool tag = false;
    
    string sIP="";
    
    
    
    for(int i=0;i<4;i++){
        //char *pk1 = itoa(Convert1byteToInteger(pkt[44+i]))
        sIP+=ss((unsigned int)pkt[44+i]);
        if(i!=3)sIP+=".";
    }    
    
    string dIP="";
    
    for(int i=0;i<4;i++){
        //char *pk2 = itoa(Convert1byteToInteger(pkt[54+i]))
        dIP+=ss((unsigned int)pkt[54+i]);
        if(i!=3)dIP+=".";
    } 
    
    for(int i=0;i<no;i++){
        
        if(stat[i].sourceIp==sIP && stat[i].destinationIP==dIP){
            stat[i].count = stat[i].count+1;
            tag = true;
            //cout<<stat[i].sourceIp<<"-->"<<stat[i].destinationIP<<" no "<<stat[i].count<<endl;
            q.push(stat[i]);
            break;
        }    
    }
    
    if(tag==false){
        stat[no].sourceIp = sIP;
        stat[no].destinationIP = dIP;
        stat[no].count=1;
        no++;
        /*cout<<stat[no-1].sourceIp<<"-->"<<stat[no-1].destinationIP<<" no "<<stat[no-1].count<<endl;*/
        q.push(stat[no]);
    }
    
    //cout<<endl<<endl<<no<<endl<<endl;
    number=no;
 return no;   
}

void relationShow(int packetNum){     

        cout<<"Top 10 relation of IP address"<<endl;
        vector<iPa>check;
        
        
    /*for(int i=0;i<20;i++){
        iPa temp = q.top();
        bool tag=false;
        
        if(i!=0){
        
            vector<iPa>::iterator it;
            
            for(it = check.begin();it!=check.end();it++ ){
                
                 iPa c = *it;
 
                 if(c.sourceIp==temp.sourceIp && c.destinationIP==temp.destinationIP){
                    tag=true;
                    //break;
                 }
                 if(tag==true)break;
            }

        }
        if(tag==true){
             i--;
                //continue;
        }  
               
       else {
           cout<<temp.sourceIp<<"---->"<<temp.destinationIP<<"  transfer file between them is "<<temp.count<<endl;
            check.push_back(temp);
            q.pop();
        }
        //iPa old = temp;
    }*/
    int ck=0;
    cout<<ck<<packetNum<<endl;
    iPa store[packetNum];
    
        while(number--){
        
            iPa temp = q.top();
            bool tag=false;
            
              /*cout<<temp.sourceIp<<"---->"<<temp.destinationIP<<"  transfer file between them is "<<temp.count<<endl;*/
             //cout<<ck<<endl;
            if(ck!=0){
                
                for(int i=0;i<=ck;i++){
                    if(store[i].sourceIp==temp.sourceIp && store[i].destinationIP==temp.destinationIP){
                    //cout<<"mara"<<endl;
                    tag=true;
                    break;
                    }    
                    
                }
            }
            else {
              cout<<temp.sourceIp<<"---->"<<temp.destinationIP<<"  transfer file between them is "<<temp.count<<endl;
            }
            
           if(tag==false) 
            cout<<temp.sourceIp<<"---->"<<temp.destinationIP<<"  transfer file between them is "<<temp.count<<endl;
            
            store[ck] = temp;
            
            q.pop();
            
            ck++;
           
      }
        
     
    
}


