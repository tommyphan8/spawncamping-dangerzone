#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

/*
 * Read the URLS from the text file
 * @param string - name of the text file
 * return - the vector storing the URLs
 * 
 */
vector<string> getURL(const string);


/*
 * fork child processes parallel
 * @param vector - vector that contains URLS
 * 
 */
void forkChild(const vector<string>);

int main()
{
	vector<string> url = getURL("urls.txt"); //urls is the name of text file
	
	forkChild(url);
	
	return 0;

	
}

void forkChild(const vector<string> url)
{
	string link;
	int n = url.size(); //number of links stored in vector
	
	pid_t pid;
	
	for (int i = 0; i < n; i++)
	{
		link = url[i];
		pid = fork();
		
		if (pid < 0)
		{
			cout << "error" << endl;
			abort();
		}
		else if ( pid == 0)
		{
			break;
		}
		
	}
	
	if (pid == 0)
	{
		execlp("/usr/bin/wget", "wget", "-q", link.c_str(), NULL);
	}
	
	for (int i = 0; i < n; i++)
	{
		wait(NULL);
	}
	
//~ 
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ link = url[i];
		//~ if ((pid[i] = fork()) < 0)
		//~ {
			//~ cout << "error" << endl;
			//~ abort();
		//~ }
		//~ else if (pid[i] == 0)
		//~ {
			//~ execlp("/usr/bin/wget", "wget", "-q", link.c_str(), NULL);
			//~ exit(0);
		//~ }
		//~ 
	//~ }
	//~ cout << "twtSKDJFLSEAR";
	//~ //wait() to prevent zombie processes
	//~ while (n > 0); //run until number of links in vector/processes
	//~ {
		//~ cout << "test";
		//~ wait(0); 
		//~ n--;
	//~ }
}


vector<string> getURL(const string textFile)
{
	vector<string> vec;
	string line;
	fstream fs (textFile.c_str(), fstream::in);
	if (fs.is_open());
	{
		while(getline(fs, line))
		{
			vec.push_back(line);
			
		}
		fs.close();
	}
		
	return vec;
	
}
