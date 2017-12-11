#include <pololu/orangutan.h>
#include <string.h>
#include <errno.h>



///////////////////////Aldagai konstanteen erazagupena/////////////////////////////////////////////////

	
	//Irakurtzen den teklarako bufferra
	char tekla_buffer[3];

	//Zain dagoen tekla
	char tekla=' ';
	//Defektuzko hasierako abiadura
	int abiadura=50;
	//Aurretik zein tekla sakatu jakiteko aldagaia
	char aurrekoa;
	
////////////////////////////////////////////////////////////////////////////////////////////////////


void mugitu_azeleratuz()
{
	//Abiadura 0-z hasieratuz
	int abiadura = 0;
	serial_set_baud_rate(115200);
	clear();
	//Hasi edota atzera botoia sakatu arte
	while(tekla!='h' && tekla!='a')
	{
		//tekla_buffer[0] jasotzen den tekla izango da
		//RFCOMM0 portutik tekla_buffer-en datuak jasotzen egongo da 'h' iritsi arte
		serial_receive_blocking(tekla_buffer,1,50);
		tekla = tekla_buffer[0];
		
	}
	//Interfazeko Stop botoia edota atzera botoia sakatu artean
	while(tekla!='s' && tekla!='a')
	{
		//char aurrekoa;
		//RFCOMM0 portutik  tekla buffer-en jasoko da interfazean sakaturiko botoia, aurrera/atzera/eskuin/ezker-erako norabidea hartzeko
		serial_receive_blocking(tekla_buffer,1,200);
		//tekla aldagaiak hartuko du tekla_buffer-en edukia
		tekla = tekla_buffer[0];
		lcd_goto_xy(0,0);
		print_long(abiadura);
		switch(tekla)
		{
			
			//Aurrerantz doa robota
			case 'u':
				//abiadura gehitzen
				abiadura=abiadura+1;
				
				set_motors(abiadura,abiadura);
				//Frenatzerako orduan azkeneko aldiz aurrerantz ari zela jakiteko 
				aurrekoa = 'u';
				break;
			//Atzerantz doa robota	
			case 'd':
				//abiadura gehitzen
				abiadura=abiadura+1;
				set_motors(-abiadura,-abiadura);
				//Frenatzerako orduan azkeneko aldiz atzerantz ari zela jakiteko 
				aurrekoa = 'd';
				break;
			//Ezkerrerantz doa robota	
			case 'l':
				//abiadura gehitzen
				abiadura=abiadura+1;
				//Aurrerantz badoa robota,ezkerrerantz biraketa aurrerantz egingo da
				if(aurrekoa == 'u')
				{
					
					set_motors(abiadura/2,abiadura);
					delay_ms(500);
					set_motors(abiadura,abiadura);
				}
				
				//Atzerantz badoa robota,ezkerrerantz biraketa atzerantz egingo da
				if(aurrekoa == 'd')
				{
					
					set_motors(-abiadura/2,-abiadura);
					delay_ms(500);
					set_motors(-abiadura,-abiadura);
				}
				break;
				
			//Eskuinerantz doa robota	
			case 'r':
				//abiadura gehitzen
				abiadura=abiadura+1;
				//Aurrerantz badoa robota,eskuinerantz  biraketa aurrerantz egingo da
				if(aurrekoa == 'u')
				{
					
					set_motors(abiadura,abiadura/2);
					delay_ms(500);
					set_motors(abiadura,abiadura);
				}
				
				//Atzerantz badoa robota,eskuinerantz biraketa atzerantz egingo da
				if(aurrekoa == 'd')
				{
					
					set_motors(-abiadura,-abiadura/2);
					delay_ms(500);
					set_motors(-abiadura,-abiadura);
				}
				break;
				
			//Frenatzen doa robota	
			case 'b':
				//abiadura mantsotzen
				abiadura = abiadura-1;
				//Jakin ahal izateko frenatu ondoren aurrerantz edo atzerantz dihoan robota
				if(aurrekoa == 'u')
				{
					set_motors(abiadura,abiadura);
				}
				if(aurrekoa == 'd')
				{
					set_motors(-abiadura,-abiadura);
				}
				
				break;
			//Robota geratu egingo da
			case 'p':
				set_motors(0,0);
				break;
				
			//Robota geratu egingo da
			case 's':
				set_motors(0,0);
				break;	
		
		}
		//Buffera hustu
		tekla_buffer[0]=' ';		
	}
	
}

void mugitu_eskubi_ezker_zoro()
{
	// configure serial clock for 115.2 kbaud
	serial_set_baud_rate(115200);
	//Hasi edota atzera botoia sakatu arte
	while(tekla!='h' && tekla!='a')
	{
		//tekla_buffer[0] jasotzen den tekla izango da
		//tekla_buffer[1] jasotzen den abiadura izango da
		//RFCOMM0 portutik tekla_buffer-en abiadura jasotzen egongo da 'h' iritsi arte
		serial_receive_blocking(tekla_buffer,2,50);
		tekla = tekla_buffer[0];
		abiadura = (int)tekla_buffer[1];
	}
	print_long(abiadura);
	//Interfazeko Stop botoia edota atzera botoia sakatu artean
	while(tekla != 's' && tekla!='a')	
	{
		//RFCOMM0 portutik tekla_buffer-en jasoko da interfazean sakaturiko botoia edo aurrera/atzera/eskuin/ezker-erako norabidea hartzeko
		serial_receive_blocking(tekla_buffer,1,200);
		//tekla aldagaiak hartuko du tekla_buffer-en edukia
		tekla = tekla_buffer[0];
		
		switch(tekla)
		{
			//Aurrerantz doa robota
			case 'u':
				set_motors(abiadura,abiadura);
				aurrekoa = 'u';
				break;
			//Atzerantz doa robota
			case 'd':
				set_motors(-abiadura,-abiadura);
				aurrekoa = 'd';
				break;
			//Ezkerrerantz hasiko da biraka
			case 'l':
			//Aurrerantz badoa robota,ezkerrerantz biraketa aurrerantz egingo da
				if(aurrekoa == 'u')
				{
					set_motors(0,abiadura);
				}
				
				//Atzerantz badoa robota,ezkerrerantz biraketa atzerantz egingo da
				if(aurrekoa == 'd')
				{
					set_motors(0,-abiadura);
				}
				
				
				break;
			//Eskuinerantz hasiko da biraka
			case 'r':
				if(aurrekoa == 'u')
				{
					set_motors(abiadura,0);
				}
				
				//Atzerantz badoa robota,ezkerrerantz biraketa atzerantz egingo da
				if(aurrekoa == 'd')
				{
					set_motors(-abiadura,0);
				}
				
				break;
			//Robota geratu egingo da
			case 'p':
				set_motors(0,0);
				break;
			//Robota geratu egingo da
			case 's':
				set_motors(0,0);
				break;
	
		}
		//Buffera hustu
		tekla_buffer[0]=' ';
	}
	
}

void mugitu_mandoarekin()
{
		//posizio aldagaiak
		int posx,posy,aurrekoaX,oraingoaX,aurrekoaY,oraingoaY;
		//Hasieraketak 0-ra
		aurrekoaY=0;
		aurrekoaX=0;
		abiadura = 0;
		int aurrera;
		serial_set_baud_rate(115200);
		//Hasi edota atzera botoia sakatu arte
		while(tekla != 'h' && tekla!='o')	
		{
			//RFCOMM0 portutik tekla_buffer 'h' edo 'a' jaso arte datuak jasotzen egongo da
			serial_receive_blocking(tekla_buffer,1,200);
			tekla = tekla_buffer[0];
		}
		
		//Interfazeko Stop botoia edota atzera botoia sakatu artean
		while(tekla!='s' && tekla!='o')
		{
			//RFCOMM0 portutik sakaturiko tekla, arratoiaren x eta y posizioak jasoko dira 
			serial_receive_blocking(tekla_buffer,3,50);
			tekla = tekla_buffer[0];
			//Jasotako arratoiaren y posizioa
			posy = (int)tekla_buffer[1];
			//Jasotako arratoiaren x posizioa
			posx = (int)tekla_buffer[2];
			//Jaso berri den y eta x posizioarekin eguneratzen dira oraingoaX eta oraingoaY aldagaiak
			oraingoaY = posy;
			oraingoaX = posx;
			
			//---------------------------Y atala(aurrera-atzera)-----------------------------------------
			//Alderatzen da aurretik jaso den y posizioa, orain jaso denarekin
			//oraingo y posizioa, aurrekoa baino txikiagoa bada atzerantz doala esan nahi du
			if(oraingoaY>aurrekoaY)
			//aurrerantz doa robota
			{
				abiadura++;
				
				set_motors(-abiadura,-abiadura);
				//azkeneko aldiz aurrerantz zihoala adierazteko
				aurrera = 1;
			}
			//Alderatzen da aurretik jaso den y posizioa, orain jaso denarekin
			//oraingo y posizioa, aurrekoa baino txikiagoa bada atzerantz doala esan nahi du
			if(oraingoaY<aurrekoaY)
			//atzerantz doa robota
			{
				//Abiadura unitate batean gehitzen da
				abiadura++;
				set_motors(abiadura,abiadura);
				//azkeneko aldiz atzerantz zihoala adierazteko
				aurrera = 0;
			}
			
			
			
			//---------------------------X atala(ezker-eskuin)-----------------------------------------
			//Alderatzen da aurretik jaso den x posizioa, orain jaso denarekin
			//oraingo x posizioa, aurrekoa baino txikiagoa bada atzerantz doala esan nahi du
			//+5 eko borne bat jartzen da posizio aldaketa txiki bat egoten bada mugi ez dadin
			if(oraingoaX>aurrekoaX+5)
			//eskuinerantz doa robota
			{
				abiadura++;
				if(aurrera == 1)
				//aurrerantz doa robota
				{
					
					set_motors(-abiadura,-abiadura/2);
					delay_ms(500);
					set_motors(-abiadura,-abiadura);
				}
				//oraingo y posizioa, aurrekoa baino txikiagoa bada atzerantz doala esan nahi du
				if(aurrera == 0)
				//atzerantz doa robota
				{
					
					set_motors(abiadura,abiadura/2);
					delay_ms(500);
					set_motors(abiadura,abiadura);
				}
				aurrekoaX=oraingoaX;

				
			}
			//Alderatzen da aurretik jaso den y posizioa, orain jaso denarekin
			//oraingo y posizioa, aurrekoa baino txikiagoa bada atzerantz doala esan nahi du
			//-5 eko borne bat jartzen da posizio aldaketa txiki bat egoten bada mugi ez dadin
			if(oraingoaX<aurrekoaX-5)
			//ezkerrerantz doa robota
			{
				//Abiadura unitate batean gehitzen da
				abiadura++;
				if(aurrera == 1)
				//aurrerantz doa robota
				{
					set_motors(-abiadura/2,-abiadura);
					delay_ms(500);
					set_motors(-abiadura,-abiadura);
				}
				//oraingo y posizioa, aurrekoa baino txikiagoa bada atzerantz doala esan nahi du
				if(aurrera == 0)
				//atzerantz doa robota
				{
					set_motors(abiadura/2,abiadura);
					delay_ms(500);
					set_motors(abiadura,abiadura);
				}
				aurrekoaX=oraingoaX;
			}
			
			//Robotak frenatu egingo du
			if(tekla=='b')
			{
				abiadura--;
				
				if(aurrera == 1)
				//aurrerantz doa robota
				{
					set_motors(-abiadura,-abiadura);
				}
				//oraingo y posizioa, aurrekoa baino txikiagoa bada atzerantz doala esan nahi du
				if(aurrera == 0)
				//atzerantz doa robota
				{
					set_motors(abiadura,abiadura);
				}
			}
			//Robota geratu egingo da
			if(tekla == 'p')
			{	
				set_motors(0,0);
				abiadura = 0;
			}
			
			//Robota geratu egingo da
			if(tekla == 's')
			{	
				set_motors(0,0);
				abiadura = 0;
			}
			aurrekoaY=oraingoaY;
			//aurrekoaX=oraingoaX;
			tekla_buffer[0] = ' ';			
		}
		
}

//Abiadura finkatua
void mugitu_eskubi_ezker_normal()
{
	//configure serial clock for 115.2 kbaud
	serial_set_baud_rate(115200);
	//Hasi edota atzera botoia sakatu arte
	while(tekla!='h' && tekla!='a')
	{
		//tekla_buffer[0] jasotzen den tekla izango da
		//tekla_buffer[1] jasotzen den abiadura izango da
		////RFCOMM0 portutik tekla_buffer-en abiadura jasotzen egongo da 'h' edo 'a' iritsi arte
		serial_receive_blocking(tekla_buffer,2,50);
		tekla = tekla_buffer[0];
		abiadura = (int)tekla_buffer[1];
	}
	
	//Interfazeko Stop botoia edota atzera botoia sakatu artean
	while(tekla != 's' && tekla!='a')	
	{
		//RFCOMM0 portutik  tekla buffer-en jasoko da interfazean sakaturiko botoia, aurrera/atzera/eskuin/ezker-erako norabidea hartzeko
		serial_receive_blocking(tekla_buffer,1,200);
		//tekla aldagaiak hartuko du tekla_buffer-en edukia
		tekla = tekla_buffer[0];
		
		switch(tekla)
		{
			//Aurrerantz doa robota
			case 'u':
				set_motors(abiadura,abiadura);
				aurrekoa = 'u';
				break;
			//Atzerantz doa robota		
			case 'd':
				set_motors(-abiadura,-abiadura);
				aurrekoa = 'd';
				break;
			//Ezkerrantz giratuko da 90º-z		
			case 'l':
			
				//Aurrerantz badoa robota,ezkerrerantz biraketa aurrerantz egingo da
				if(aurrekoa == 'u')
				{
					set_motors(0,64);
					delay_ms(500);
					set_motors(0,0);
				}
				
				//Atzerantz badoa robota,ezkerrerantz biraketa atzerantz egingo da
				if(aurrekoa == 'd')
				{
					set_motors(0,-64);
					delay_ms(500);
					set_motors(0,0);
				}
				break;
				
			//Eskuinerantz giratuko da 90º-z	
			case 'r':
			
				//Aurrerantz badoa robota,ezkerrerantz biraketa aurrerantz egingo da
				if(aurrekoa == 'u')
				{
					set_motors(64,0);
					delay_ms(500);
					set_motors(0,0);
				}
				
				//Atzerantz badoa robota,ezkerrerantz biraketa atzerantz egingo da
				if(aurrekoa == 'd')
				{
					set_motors(-64,0);
					delay_ms(500);
					set_motors(0,0);
				}
				
				break;
			//Robota geratu egingo da
			case 'p':
				set_motors(0,0);
				break;
			//Robota geratu egingo da
			case 's':
				set_motors(0,0);
				break;
		}
		//Buffera hustu
		tekla_buffer[0]=' ';
	}
}

int main()
{
	//Pantaila garbitu
	clear();
	//Bukaeran hau kendu behar da
	long bat = read_battery_millivolts();
	print_long(bat);
	serial_set_baud_rate(115200);
	while(tekla != 'i')	
	{
		serial_receive_blocking(tekla_buffer,1,200);
		tekla = tekla_buffer[0];
		switch(tekla)
		{
			//Lehenbiziko aukera, mandoarekin inalanbrikoki mugitu
			case '1':
				print("mug");
				mugitu_mandoarekin();
				break;	
			case '2':
				print("zo");
				mugitu_eskubi_ezker_zoro();
				break;
			case '3':
				print("normal");
				mugitu_eskubi_ezker_normal();
				break;
			case '4':
				print("azeler");
				mugitu_azeleratuz();
				break;
			
		}
		
	}
	clear();
	print(" Itzali  ");
	lcd_goto_xy(0,1);
	print(" nazazu ");
}

