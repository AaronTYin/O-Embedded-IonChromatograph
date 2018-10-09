#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main()
{
	int fd,led;
	char buf[100];
	int i=0;

	led=open("/dev/leds",O_RDONLY);
	if(led<0) exit(1);

	fd=open("/dev/adc",O_RDWR);
	if(fd<0) exit(1);

	while(1)
	{
		i=read(fd,buf,sizeof(buf)-1);
		buf[i]='\0';
		sscanf(buf,"%d",&i);

		printf("AD=%d\n",i);
		sleep(1);

		ioctl(led,0,0);//LED control (file,on/off,adress)
	}
	close(fd);
	close(led);

	return 0;
}
