# spawncamping-dangerzone

Serial Downloader
The serial downloader shall download files one by one. After the parent process has read and
parsed the urls.txt file, it shall proceed as follows:
1. The parent process forks off a child process.
2. The child uses execlp("/usr/bin/wget", "wget", <URL STRING1>, NULL) system call
in order to replace its program with wget program that will download the first file in
urls.txt (i.e. the file at URL <URL STRING1>).
3. The parent executes a wait() system call until the child exits.
4. The parent forks off another child process which downloads the next file specified in
urls.txt.
5. Repeat the same process until all files are downloaded.

Parallel Downloader
1. The parent forks off n children, where n is the number of URLs in urls.txt.
2. Each child executes execlp("/usr/bin/wget", "wget", <URL STRING>, NULL) system
call where each <URL STRING> is a distinct URL in urls.txt.
3. The parent calls wait() (n times in a row) and waits for all children to terminate.
4. The parent exits.
Please note: while the parallel downloader executes, the outputs from different children may
intermingle. This is acceptable.
