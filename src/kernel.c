#include "include/system.h"
#include "include/util.h"
#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/isr.h"
#include "include/idt.h"
#include "include/serial.h"

kmain()
{
	isr_install();
	clearScreen();
	create_descriptor(0, 0, 0);
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL3));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL3));
	int kapp = 0;
	int la = 0;
	string lastcmd;
	int test;
	int cmdlineip = 0;
	int anim = 0;
	string cmdline;
	int needexit = 0;
	int cc;
	cc = 1;
	print("Debugging was started by the system on port COM1");
	newline();
	newline();
	print("Tip: If a command does not work try removing the last character. ");
	newline();
	print("Example: osver - osve ");
	newline();
	
	do {
		if (kapp == 0){
			print("\nVMOS> ");
			cmdline = strtok(readStr()," ");
			newline();
			if(strEql(cmdline, "osver"))
			{
				printch((char)176);
				printch((char)177);
				printch((char)178);
				print(" VMOS 1.0.0 build 68 ");
				printch((char)178);
				printch((char)177);
				printch((char)176);
				newline();
			}
			else if(strEql(cmdline, "cls"))
			{
				clearScreen();
			}
			else if(strEql(cmdline, "reboot"))
			{
				reboot();
			}
			else if(strEql(cmdline, "lastcmd"))
			{
				print(cmdline);
			}
			else if(strEql(cmdline, "crash"))
			{
				test = 5/0;
			}
			else if(strEql(cmdline, "debug"))
			{
				ss_serial();
			}
			else
			{
				print_serial("0x01 ", 0);
				newline();
				printch((char)96);
				print(cmdline);
				printch((char)96);
				print(" is not recognzed as an internal or external command");
			}
			
			newline();
		} 
		else if(kapp = 1)
		{
			if (anim == 0) {
				//clearScreen();
				printch((char)176);
				printch((char)177);
				printch((char)178);
				printch((char)177);
				printch((char)176);
				printch((char)177);
				printch((char)178);
				printch((char)177);
				printch((char)176);
				anim++;
			}
			else if (anim == 1) {
				//clearScreen();
				printch((char)177);
				printch((char)178);
				printch((char)177);
				printch((char)176);
				printch((char)177);
				printch((char)178);
				printch((char)177);
				printch((char)176);
				printch((char)177);
				anim++;
			}
			else if (anim == 2) {
				//clearScreen();
				printch((char)178);
				printch((char)177);
				printch((char)176);
				printch((char)177);
				printch((char)178);
				printch((char)177);
				printch((char)176);
				printch((char)177);
				printch((char)178);
				anim++;
			}
			else if (anim == 3) {
				anim = 0;
			}
		}
	} while (la == 0);
}
