#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;



/*
 * Read the URLs from the file
 * @param urls - the URLs to download
 */
void readUrls(vector<string>& urls)
{
/* Open the file */
/* The URL buffer */
/* Make sure the file was opened */
/* Read the entire file */
	string line;
	ifstream myfile("url.txt");
	if (myfile.is_open());
	{
		while(getline (myfile, line))
		{
			urls.push_back(line);
		}
	}
/* Read the buffer */
/* Are we at the end of the file */
/* Close the file */
	
}



int main()
{
	
	/* Read the URL files */
	vector<string> urls;
		
	/* Read the URLs */
	readUrls(urls);
	
	//string link;
	pid_t pid;
	string link;
	
	for (int i = 0; i < 7; i++)
	{
		link = urls[i];
		pid = fork();
		if (pid == 0)
		{
			execlp("/usr/bin/wget","wget", link.c_str(), NULL);
		}
		else if (pid > 0)
		{
			
			wait(NULL);
			cout << "Downloading number: " << i << " completed " << link << " " << endl;
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


