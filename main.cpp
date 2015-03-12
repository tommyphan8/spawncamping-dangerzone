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
		
	string link1 = "http://bingweb.binghamton.edu/~mgofman1/rbac-pat-slides.ppt.zip";
	pid_t pid;
	pid = fork();
	
	
	if (pid == 0)
	{
		execlp("/usr/bin/wget","wget", link1.c_str(), NULL);
	}
	else if (pid > 0)
	{
		
		wait(NULL);
		cout << "complete";
	}
	else
	{
		cout << "fail";
	}
	return 0;
}
