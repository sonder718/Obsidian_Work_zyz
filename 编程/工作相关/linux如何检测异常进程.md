1.  使用top命令查看是否有**占用CPU较高的进程**，如果有，那么这些进程很可能是异常进程。可以使用`top -c`命令查看进程的详细信息，包括进程的PID、CPU使用率等。如果发现某个进程一直占用CPU资源，就需要进一步检查这个进程是否异常。

2.  检查定时任务crontab，可以使用`crontab -l`命令查看当前用户的定时任务列表。如果发现有可疑的定时任务，就需要进一步检查这些定时任务是否与异常进程有关。

3.  使用netstat命令列出进程打开或使用的文件，可以使用`netstat -nap`命令查看当前系统中所有的网络连接。如果发现有可疑的网络连接，就需要进一步检查这些网络连接是否与异常进程有关。

4.  使用lsof命令查看系统中打开的文件，可以使用`lsof -p <PID>`命令查看某个进程打开的文件。如果发现某个进程打开了可疑的文件，就需要进一步检查这个进程是否异常。

5.  使用ps命令查看进程的详细信息，可以使用`ps -ef`或`ps axu`命令查看系统中所有的进程。如果发现某个进程异常，可以通过`kill <PID>`命令杀死这个进程。