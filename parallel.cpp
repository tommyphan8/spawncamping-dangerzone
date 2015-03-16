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
 */*
vector<string> getURL(string);


/*
 * fork child processes parallel
 * @param vector - vector that contains URLS
 * 
 */
void forkChild(vector<string>);

int main()
{
	vector<string> url = getURL("urls.txt");
	
	forkChild(url);
	
	return 0;

	
}

void forkChild(vector<string> url)
{
	string link;
	int n = url.size(); //number of links stored in vector
	pid_t pid[n];
	
	for (int i = 0; i < n; i++)
	{
		link = url[i];
		if ((pid[i] = fork()) < 0)
		{
			cout << "error" << endl;
			exit(2);
		}
		else if (pid[i] == 0)
		{
			execlp("/usr/bin/wget", "wget", link.c_str(), NULL);
			exit(0);
		}
		
	}
	
	//wait() to prevent zombie processes
	while (n > 0); //run until number of links in vector/processes
	{
		wait(NULL); 
		n--;
	}
}


vector<string> getURL(string textFile)
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
