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
 * Read the URLS from the text file
 * @param string - name of the text file
 * return - the vector storing the URLs
 * 
 */
vector<string> getURL(const string textFile);



/*
 * Creates child processes serial
 * @param vector<string> - vector containing URLs
 */
void createChild(const vector<string> urls);

int main()
{
	
	/* Read the URL files */
	vector<string> urls = getURL("urls.txt"); //urls.txt is the name of text file
		
	//~ // Execute the createChild function passing the vector containing URLs
	createChild(urls);
	
	
	return 0;
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

void createChild(const vector<string> urls)
{
	int n = urls.size();
	pid_t pid;
	string link;
	
	for (int i = 0; i < n; i ++)
	{
		link = urls[i];
		pid = fork();
		if (pid == 0)
		{
			execlp("/usr/bin/wget","wget", "-q", link.c_str(), NULL);
		}
		else if (pid > 0)
		{			
			wait(NULL);
		}
		else
		{
			cout << "fail";
		}
		
	}
	
}



