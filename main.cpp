#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <vector>

using namespace std;


int main()
{
	string links[2] = {"http://www.cisco.com/networkers/nw04/presos/docs/NMS-1N02.pdf",
		 "http://www.erlang.org/doc/apps/snmp/snmp.pdf"}; 
	string link1;
	pid_t pid;
	
	for (int i = 0; i < 2; i++)
	{
		link1 = links[i];
		pid = fork();
		if (pid == 0)
		{
			execlp("/usr/bin/wget","wget", link1.c_str(), NULL);
		}
		else if (pid > 0)
		{
			
			wait(NULL);
			cout << "complete" << link1 << " " << endl;
		}
		else
		{
			cout << "fail";
		}
	}
	//pid = fork();
	
	//~ if (pid == 0)
	//~ {
		//~ execlp("/usr/bin/wget","wget", link1.c_str(), NULL);
	//~ }
	//~ else if (pid > 0)
	//~ {
		//~ 
		//~ wait(NULL);
		//~ cout << "complete";
	//~ }
	//~ else
	//~ {
		//~ cout << "fail";
	//~ }
	return 0;
}
