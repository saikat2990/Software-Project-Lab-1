#include<iostream>

using namespace std;

int globalHeaderValue(int globalHeader[]){

    for(int i=0;i<24;i++){

        if(i<4){

            if(i==0)cout<<"Gheader -------"<<endl;

            printf("%0.20x ",globalHeader[i]);
        }
        else if(i>=4 && i<6){

            if(i==4)cout<<"Major version -----"<<endl;

            printf("%0.20x ",globalHeader[i]);

        }
        else if(i>=6 && i<8){

            if(i==6)cout<<"Minor version -----"<<endl;

            printf("%0.20x ",globalHeader[i]);

        }
        else if(i>=8 && i<12){

            if(i==8)cout<<"GMTTimeOffSet   -----"<<endl;

            printf("%0.20x ",globalHeader[i]);

        }

        else if(i>=12 && i<16){

            if(i==4)cout<<"SigFigs -----"<<endl;

            printf("%0.20x ",globalHeader[i]);

        }
        else if(i>=16 && i<20){

            if(i==4)cout<<"MaximumSnapLength  -----"<<endl;

            printf("%0.20x ",globalHeader[i]);

        }
        else if(i>=20 && i<24){

            if(i==4)cout<<"LinkLayerProtocol -----"<<endl;

            printf("%0.20x ",globalHeader[i]);

        }
    }

return 0;
}
