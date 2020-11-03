#include <SPI.h>
#include <Ethernet.h>
int stp=0;
int nombre;
float Ubatvide;
int SOC;
int Heure;
int Jour;
int Rinbat;
int Ndsdv;

byte mac[] = { 0x90 , 0xA2 , 0xDA , 0x0D , 0x7F , 0x98 };
byte DNS[] = { 10 , 66 , 25 , 1 };
byte gateway[] ={ 10, 66 ,23 , 242 };
byte mask[] = { 255, 255 , 248 , 0 };


byte ip[4]; //tableau contenant l'IP de l'arduino
int i=0;

//char server[] = "spe.sin.apo.free.fr"; //nom du site FREE
char server[] = "10.66.16.244"; //Avec Wamp, on donne l'IP du PC
EthernetClient client;

void setup() {
	//Open serial communiactions and wait for the port to open :
	Serial.begin(9600);//mis en marche laison série 
	
	if(Ethernet.begin(mac)==0 {
		Serial.println("Failed to configure Ethernet using DHCP");
		for(;;);
	}
	//print your local Ip address;
	Serial.print("My IP address: "); Serial.println(Ethernet.localIP());
	Serial.print("My IP address: ");
	for (i=0; i<4; i++) {
		//print the value of each byte of the IP address:
		Serial.print(ip[i] = Ethernet.localIP()[i]);
		if(i!=3) Serial.print(".");
	}
	Serial.println();
	
	
	Ethernet.begin(mac, ip , DNS , Gateway, mask);
	delay(1000);
	Serial.println("Connecting..");
}

void loop()
{// connexion au PC serveur  (wampserveur avec IP du PC ou nom du site free)


	if (stp<1)
	{stp=stp+1;
	Ndsdv=2
		if (client.connect(server, 80)){
			Serial.println("connected");
			//lancement du fichier ecriture1.php qui se trouve www/orihect/de WAMPSERVEUR
			
			
			client.print("GET http://10.66.16.244/Project/Ecriture.php?");
			client.print("Ndsdv=");
			client.print(Ndsdv);//la valeur de la variable du numérot de série du véhicule
			client.print("&");
			
			client.print("Jour=");
			client.print(Jour);//la valeur de la variable de la date du contrôle
			client.print("&");
			
			client.print("Heure=");
			client.print(Heure);//la valeur de la variable dde l'heure du contrôle
			client.print("&");
			
			client.print("Ubatvide=");
			client.print(Ubatvide);//la valeur de la variable de la tension à vide
			client.print("&");
			
			client.print("Rinbat=");
			client.print(Rinbat);//la valeur de la variable de la résisstaznce interne
			client.print("&");
			
			client.print("SOC");
			client.print(SOC);//la valeur de la variable de la SOC
			
			client.print("HTTP/1.1");
			//client.println("Host: spe.sin.apo.free.fr") ;// sur l'hébergement free
			client.println("Host: 10.66.16.244");
			Serial.println(Ndsdv);
			Serial.println("Connection: close");
			client.println();
			client.stop();
			client.println();
			
		}
		else {// If you didn't get a connection to the server :
		Serial.println("Connection failed");
		}delay(1000);
		
}
	
}