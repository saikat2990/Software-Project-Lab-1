#include<stdio.h> 
#include <cstring>
#include <cctype>//For standard things
#include<stdlib.h>    //malloc
#include<string.h> 
#include<netinet/ip_icmp.h>
#include<netinet/udp.h>
#include<netinet/tcp.h>
#include<netinet/ip.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<asm/types.h>
#include<math.h>
#include<unistd.h>
#include<signal.h>
#include<linux/if_packet.h>
#include<linux/if_ether.h>
#include<linux/if_arp.h>
//#include "printPacket.cpp"
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <asm/types.h>

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


#define DEVICE      "eth0"
#define ETH_ALEN	6		/* Octets in one ethernet addr	 */
#define ETH_HLEN	14		/* Total octets in header.	 */
#define ETH_ZLEN	60		/* Min. octets in frame sans FCS */
#define ETH_DATA_LEN	1500		/* Max. octets in payload	 */
#define ETH_FRAME_LEN	1514		/* Max. octets in frame sans FCS */
#define ETH_FCS_LEN	4		/* Octets in the FCS		 */

/*
 *	These are the defined Ethernet Protocol ID's.
 */

#define ETH_P_LOOP	0x0060		/* Ethernet Loopback packet	*/
#define ETH_P_PUP	0x0200		/* Xerox PUP packet		*/
#define ETH_P_PUPAT	0x0201		/* Xerox PUP Addr Trans packet	*/
#define ETH_P_IP	0x0800		/* Internet Protocol packet	*/
#define ETH_P_X25	0x0805		/* CCITT X.25			*/
#define ETH_P_ARP	0x0806		/* Address Resolution packet	*/
#define	ETH_P_BPQ	0x08FF		/* G8BPQ AX.25 Ethernet Packet	[ NOT AN OFFICIALLY REGISTERED ID ] */
#define ETH_P_IEEEPUP	0x0a00		/* Xerox IEEE802.3 PUP packet */
#define ETH_P_IEEEPUPAT	0x0a01		/* Xerox IEEE802.3 PUP Addr Trans packet */
#define ETH_P_DEC       0x6000          /* DEC Assigned proto           */
#define ETH_P_DNA_DL    0x6001          /* DEC DNA Dump/Load            */
#define ETH_P_DNA_RC    0x6002          /* DEC DNA Remote Console       */
#define ETH_P_DNA_RT    0x6003          /* DEC DNA Routing              */
#define ETH_P_LAT       0x6004          /* DEC LAT                      */
#define ETH_P_DIAG      0x6005          /* DEC Diagnostics              */
#define ETH_P_CUST      0x6006          /* DEC Customer use             */
#define ETH_P_SCA       0x6007          /* DEC Systems Comms Arch       */
#define ETH_P_TEB	0x6558		/* Trans Ether Bridging		*/
#define ETH_P_RARP      0x8035		/* Reverse Addr Res packet	*/
#define ETH_P_ATALK	0x809B		/* Appletalk DDP		*/
#define ETH_P_AARP	0x80F3		/* Appletalk AARP		*/
#define ETH_P_8021Q	0x8100          /* 802.1Q VLAN Extended Header  */
#define ETH_P_IPX	0x8137		/* IPX over DIX			*/
#define ETH_P_IPV6	0x86DD		/* IPv6 over bluebook		*/
#define ETH_P_PAUSE	0x8808		/* IEEE Pause frames. See 802.3 31B */
#define ETH_P_SLOW	0x8809		/* Slow Protocol. See 802.3ad 43B */
#define ETH_P_WCCP	0x883E		/* Web-cache coordination protocol
					 * defined in draft-wilson-wrec-wccp-v2-00.txt */
#define ETH_P_PPP_DISC	0x8863		/* PPPoE discovery messages     */
#define ETH_P_PPP_SES	0x8864		/* PPPoE session messages	*/
#define ETH_P_MPLS_UC	0x8847		/* MPLS Unicast traffic		*/
#define ETH_P_MPLS_MC	0x8848		/* MPLS Multicast traffic	*/
#define ETH_P_ATMMPOA	0x884c		/* MultiProtocol Over ATM	*/
#define ETH_P_ATMFATE	0x8884		/* Frame-based ATM Transport
					 * over Ethernet
					 */
#define ETH_P_PAE	0x888E		/* Port Access Entity (IEEE 802.1X) */
#define ETH_P_AOE	0x88A2		/* ATA over Ethernet		*/
#define ETH_P_TIPC	0x88CA		/* TIPC 			*/
#define ETH_P_1588	0x88F7		/* IEEE 1588 Timesync */
#define ETH_P_FCOE	0x8906		/* Fibre Channel over Ethernet  */
#define ETH_P_FIP	0x8914		/* FCoE Initialization Protocol */
#define ETH_P_EDSA	0xDADA		/* Ethertype DSA [ NOT AN OFFICIALLY REGISTERED ID ] */

/*
 *	Non DIX types. Won't clash for 1500 types.
 */

#define ETH_P_802_3	0x0001		/* Dummy type for 802.3 frames  */
#define ETH_P_AX25	0x0002		/* Dummy protocol id for AX.25  */
#define ETH_P_ALL	0x0003		/* Every packet (be careful!!!) */
#define ETH_P_802_2	0x0004		/* 802.2 frames 		*/
#define ETH_P_SNAP	0x0005		/* Internal only		*/
#define ETH_P_DDCMP     0x0006          /* DEC DDCMP: Internal only     */
#define ETH_P_WAN_PPP   0x0007          /* Dummy type for WAN PPP frames*/
#define ETH_P_PPP_MP    0x0008          /* Dummy type for PPP MP frames */
#define ETH_P_LOCALTALK 0x0009		/* Localtalk pseudo type 	*/
#define ETH_P_CAN	0x000C		/* Controller Area Network      */
#define ETH_P_PPPTALK	0x0010		/* Dummy type for Atalk over PPP*/
#define ETH_P_TR_802_2	0x0011		/* 802.2 frames 		*/
#define ETH_P_MOBITEX	0x0015		/* Mobitex (kaz@cafe.net)	*/
#define ETH_P_CONTROL	0x0016		/* Card specific control frames */
#define ETH_P_IRDA	0x0017		/* Linux-IrDA			*/
#define ETH_P_ECONET	0x0018		/* Acorn Econet			*/
#define ETH_P_HDLC	0x0019		/* HDLC frames			*/
#define ETH_P_ARCNET	0x001A		/* 1A for ArcNet :-)            */
#define ETH_P_DSA	0x001B		/* Distributed Switch Arch.	*/
#define ETH_P_TRAILER	0x001C		/* Trailer switch tagging	*/
#define ETH_P_PHONET	0x00F5		/* Nokia Phonet frames          */
#define ETH_P_IEEE802154 0x00F6	/* IEEE802.15.4 frame		*/


struct sockaddr_in source,dest;
struct sockaddr saddr;
struct in_addr in;

unsigned short int Convert2byteToIntegerLeftToRight(unsigned char arr[]){

    unsigned short int itsInteger;
    itsInteger = arr[0];
    itsInteger = itsInteger<<8|arr[1];
    return itsInteger;

}

int main(){
    
    unsigned char pkt[2048],buffer[2048];
    int sockForAll;
    
    sockForAll = socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL));
    //sockForAll = socket(AF_PACKET,SOCK_RAW,htons(ETH_P_IPV6));
    
    if(sockForAll<0){
       // cout<<"cannot create a socket "<<endl;  
       printf("cannot create a socket  "); 
    }
    else printf(" create a socket  "); 
   
    int addrSize,dataSize;
    
    addrSize = sizeof(saddr);
    
    //data_size = recvfrom(sock_raw , buffer , 100000, 0 , &saddr , (socklen_t*)&saddr_size);
    int framenumber=1;
    
    struct ifreq ifr;
    struct sockaddr_ll socket_address;
    int ifindex = 0; 
    strncpy(ifr.ifr_name, DEVICE, IFNAMSIZ);  
    
    ifindex = ifr.ifr_ifindex;
    printf("Successfully got interface index: %i\n", ifindex);
    
    
    socket_address.sll_family = PF_PACKET;
    socket_address.sll_protocol = htons(ETH_P_IP);
    socket_address.sll_ifindex = ifindex;
    socket_address.sll_hatype = ARPHRD_ETHER;
    socket_address.sll_pkttype = PACKET_OTHERHOST;
    socket_address.sll_halen = 0;
    socket_address.sll_addr[6] = 0x00;
    socket_address.sll_addr[7] = 0x00;
    
    
    
    
    while(1){
    
        dataSize = recvfrom(sockForAll,buffer,sizeof(buffer),0,&saddr,(socklen_t*)&addrSize);
        
        unsigned char ch1 = (unsigned char)0x08;
        unsigned char ch2 = (unsigned char)0x00;
        unsigned char ch3 = (unsigned char)0x06;
        
         for(int i=16;i<dataSize+16;i++){
            pkt[i] = buffer[i-16];
        }
        //printf("\n\n\tFrame number : ----%d\n",framenumber);
        framenumber++;
        //printf("\tFrame Lenght : ----%d (with %d bits)\n",frameLength,8*frameLength);

        //printf("\n\nEthernet ....\n\n");
        //printf("\tDestination address: ----%.02x:%.02x:%.02x:%.02x:%.02x:%.02x\n",pkt[16]&0xff,
               //pkt[17]&0xff,pkt[18]&0xff,pkt[19]&0xff,pkt[20]&0xff,pkt[21]&0xff);

       // printf("\tSource address: ----%.02x:%.02x:%.02x:%.02x:%.02x:%.02x\n",pkt[22]&0xff,
             //  pkt[23]&0xff,pkt[24]&0xff,pkt[25]&0xff,pkt[26]&0xff,pkt[27]&0xff);

        //printf("\tType: ----%.02x%.02x\n",pkt[28]&0xff,pkt[29]&0xff);
        
        if(ch1==pkt[28] && ch3==pkt[29]){
            
            printf("\n\n\tit is a arp packet : ----\n");
            unsigned char temp2[2];
            temp2[0]=(unsigned char)pkt[36];
            temp2[1]=(unsigned char)pkt[37];
            
            unsigned int n =  Convert2byteToIntegerLeftToRight(temp2);

            if(n==1){
            
                printf("Opcode : request(1)\n");
                
                pkt[36] = '0x00';
                pkt[37] = '0x02';
                
                unsigned char buf_arp_ip[4];
                
                ///etherdstAddress
                
                pkt[16]='0xff';
                pkt[17]='0xff';
                pkt[18]='0xff';
                pkt[19]='0xff';
                pkt[20]='0xff';
                pkt[21]='0xff'; 
                
                ///etherSrcAddress
                
                pkt[22]='0x74';
                pkt[23]='0xc6';
                pkt[24]='0x3b';
                pkt[25]='0x87';
                pkt[26]='0x33';
                pkt[27]='0x2f'; 
                
                ///targetMacAddress
                
                pkt[48]= pkt[38];
                pkt[49]= pkt[39];
                pkt[50]= pkt[40];
                pkt[51]= pkt[41];
                pkt[52]= pkt[42];
                pkt[53]= pkt[43];
                
                ///swapIPtarget-->Sender
                 buf_arp_ip[0] = pkt[54]; 
                 buf_arp_ip[1] = pkt[55];
                 buf_arp_ip[2] = pkt[56];
                 buf_arp_ip[3] = pkt[57];
                
                ///targetIPAddress
                
                pkt[54]=pkt[44];
                pkt[55]=pkt[45];
                pkt[56]=pkt[46];
                pkt[57]=pkt[47];
                
                ///senderMacAddress
                
                pkt[38]='0x74';   
                pkt[39]='0xc6';
                pkt[40]='0x3b';
                pkt[41]='0x87';
                pkt[42]='0x33';
                pkt[43]='0x2f';
                
                ///senderIPAddress
                
                pkt[44]=buf_arp_ip[0];   
                pkt[45]=buf_arp_ip[1];
                pkt[46]=buf_arp_ip[2];
                pkt[47]=buf_arp_ip[3];
              
                    unsigned char temp[2];
                    temp[0]=(unsigned char)pkt[30];
                    temp[1]=(unsigned char)pkt[31];
                    printf("\tHardWare Type : ----%d\n",Convert2byteToIntegerLeftToRight(temp));

                    unsigned char temp1[2];
                    temp1[0]=(unsigned char)pkt[32];
                    temp1[1]=(unsigned char)pkt[33];
                    printf("\tProtocol Type : ----%d\n",Convert2byteToIntegerLeftToRight(temp1));

                    printf("\tHardWare Type : ----%d\n",int(pkt[34]));

                    printf("\tProtocol Type : ----%d\n",int(pkt[35]));
                   
                   int sent = sendto( sockForAll , pkt, 2048, 0, (struct
                            sockaddr*)&socket_address, sizeof(socket_address));        
            }
            else continue;
            
        }
    }
}
