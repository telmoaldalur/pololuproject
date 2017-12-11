#include <pololu/orangutan.h>
#include <string.h>
#include <errno.h>

// w=Vl-Vb/b

// v=Vl+Vb/2

///////////////////////Aldagai konstanteen erazagupena/////////////////////////////////////////////////



	
	//Irakurtzen den teklarako bufferra
	char tekla_buffer[3];

	//Zain dagoen tekla
	char tekla=' ';
	//Defektuzko hasierako abiadura
	int abiadura=50;

////////////////////////////////////////////////////////////////////////////////////////////////////


void mugitu_azeleratuz()
{
	//Abiadura 0-z hasieratuz
	int abiadura = 0;
	serial_set_baud_rate(115200);
	clear();
	//Hasi botoiari sakatu arte
	while(tekla!='h' && tekla!='a')
	{
		//tekla_buffer[0] jasotzen den tekla izango da
		//tekla_buffer[1] jasotzen den abiadura izango da
		//tekla_buffer-en abiadura jasotzen egongo da 'h' iritsi arte
		serial_receive_blocking(tekla_buffer,2,50);
		tekla = tekla_buffer[0];
		abiadura = (int)tekla_buffer[1];
	}
	//Interfazeko Stop botoia edota atzera botoia sakatu artean
	while(tekla!='s' && tekla!='a')
	{
		//tekla buffer-en jasoko da tekla, aurrera/atzera/eskuin/ezker-erako norabidea hartzeko
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
				break;
			//Atzerantz doa robota	
			case 'd':
				//abiadura gehitzen
				abiadura=abiadura+1;
				set_motors(-abiadura,-abiadura);
				
				break;
			//Ezkerrerantz doa robota	
			case 'l':
				//abiadura gehitzen
				abiadura=abiadura+1;
				set_motors(abiadura,abiadura/2);
				break;
			//Ezkerrerantz doa robota	
			case 'r':
				//abiadura gehitzen
				abiadura=abiadura+1;
				set_motors(abiadura/2,abiadura);
				break;
				
			//Frenatzen doa robota	
			case 'b':
				//abiadura mantsotzen
				abiadura = abiadura-1;
				set_motors(abiadura,abiadura);
				break;
			case 'p':
				set_motors(0,0);
				break;	

		}
		//
		tekla_buffer[0]=' ';		
	}
	//robota geratu egingo da
	set_motors(0,0);	
}

void mugitu_eskubi_ezker_zoro(int abiadura)
{
	// configure serial clock for 115.2 kbaud
	serial_set_baud_rate(115200);
	
	//Hasi botoiari sakatu arte
	while(tekla!='h' && tekla!='a')
	{
		//tekla_buffer[0] jasotzen den tekla izango da
		//tekla_buffer[1] jasotzen den abiadura izango da
		//tekla_buffer-en abiadura jasotzen egongo da 'h' iritsi arte
		serial_receive_blocking(tekla_buffer,2,50);
		tekla = tekla_buffer[0];
		abiadura = (int)tekla_buffer[1];
	}
	//kentzeko dago
	print_long(abiadura);
	//Interfazeko Stop botoia edota atzera botoia sakatu artean
	while(tekla != 's' && tekla!='a')	
	{
		//tekla buffer-en jasoko da tekla, aurrera/atzera/eskuin/ezker-erako norabidea hartzeko
		serial_receive_blocking(tekla_buffer,1,200);
		//tekla aldagaiak hartuko du tekla_buffer-en edukia
		tekla = tekla_buffer[0];
		
		switch(tekla)
		{
			//Aurrerantz doa robota
			case 'u':
				print("u");
				set_motors(-abiadura,-abiadura);
				break;
			//Atzerantz doa robota
			case 'd':
				print("d");
				set_motors(abiadura,abiadura);
				break;
			//Ezkerrerantz hasiko da biraka
			case 'l':
				print("l");
				set_motors(50,0);
				
				break;
			//Eskuinerantz hasiko da biraka
			case 'r':
				print("r");
				set_motors(0,50);
				break;
			case 'p':
				set_motors(0,0);
				break;
	
		}
		tekla_buffer[0]=' ';
	}
	//robota geratu egingo da
	set_motors(0,0);
	
}
/*
 Segurtasun kontuengatik abiadura erdira jeitsiko da
 
 posX maximoa =1365 minimoa = 0
 posY maximoa = 767 minimoa = 0
 abiadura maximoa = 128 minimoa = 0
 
 abiadura koefX= posx/1365
 abiaduraX = abiadura koef*128;
 
 abiadura koefY=posY/767
 abiaduraY = abiaduera koefY * 128
 * 
 Erdiko puntua(robota geldirik) X=683 Y=384
  
  */
void mugitu_mandoarekin()
{
		int posx,posy,aurrekoa,oraingoa;
		aurrekoa=0;
		abiadura = 0;
		
		serial_set_baud_rate(115200);
		//stop botoia ikutu arte;
		while(tekla != 'h' && tekla!='a')	
		{
			serial_receive_blocking(tekla_buffer,1,200);
			tekla = tekla_buffer[0];
		}
		//serial_set_baud_rate(115200);
		while(tekla!='s' && tekla!='a')
		{
			serial_receive_blocking(tekla_buffer,3,50);
			tekla = tekla_buffer[0];
			posy = (int)tekla_buffer[1];
			posx = (int)tekla_buffer[2];
			oraingoa=posy;
			if(oraingoa<aurrekoa)
			//atzerantz doa
			{
				abiadura++;
				set_motors(-abiadura,-abiadura);
			}
			
			if(oraingoa>aurrekoa)
			//aurrerantz doa
			{
				abiadura++;
				set_motors(abiadura,abiadura);
			}
			//
			if(tekla=='z')
			{
				abiadura--;
			}
			
			aurrekoa=oraingoa;			
		}
		set_motors(0,0); 
}

//Abiadura finkatua
void mugitu_eskubi_ezker_normal(int abiadura)
{
	//configure serial clock for 115.2 kbaud
	serial_set_baud_rate(115200);
	//Hasi botoiari sakatu arte
	while(tekla!='h' && tekla!='a')
	{
		//tekla_buffer[0] jasotzen den tekla izango da
		//tekla_buffer[1] jasotzen den abiadura izango da
		serial_receive_blocking(tekla_buffer,2,50);
		tekla = tekla_buffer[0];
		abiadura = (int)tekla_buffer[1];
	}
	
	print_long(abiadura);
	
	
	serial_set_baud_rate(115200);
	while(tekla != 's' && tekla!='a')	
	{
		serial_receive_blocking(tekla_buffer,1,200);
		tekla = tekla_buffer[0];
		
		switch(tekla)
		{
			case 'u':
				set_motors(-abiadura,-abiadura);
				break;
			case 'd':
				set_motors(abiadura,abiadura);
				break;
			case 'l':
				set_motors(0,64);
				delay_ms(500);
				set_motors(0,0);
				break;
			case 'r':
				set_motors(64,0);
				delay_ms(500);
				set_motors(0,0);
				break;
			case 'p':
				set_motors(0,0);
				break;
			
	
		}
		tekla_buffer[0]=' ';

	}
	set_motors(0,0);
	
}

int main()
{
	//Pantaila garbitu
	clear();
	long bat = read_battery_millivolts();
	print_long(bat);
	serial_set_baud_rate(115200);
	while(1)	
	{
		serial_receive_blocking(tekla_buffer,1,200);
		tekla = tekla_buffer[0];
		switch(tekla)
		{
			//Lehenbiziko aukera, mandoarekin inalanbrikoki mugitu
			case '1':
				print("m");
				
				mugitu_mandoarekin();
				break;	
			case '2':
				print("zo");
				mugitu_eskubi_ezker_zoro(abiadura);
				break;
			case '3':
				print("normal");
				mugitu_eskubi_ezker_normal(abiadura);
				break;
			case '4':
				print("azeler");
				mugitu_azeleratuz();
				break;
			
		}
	}
}

