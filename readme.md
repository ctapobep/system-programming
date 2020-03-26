```
brew install cmake
```

Linux stats:

```
vmstat #memory

# install sysstat
sar -n DEV 1 #network
sar -n TCP,ETCP,DEV 1
iostat -xmdz #IO for block devices excluding those that don't have anything happening
mpstat -P ALL #CPU load per processor

# install strace
sudo strace -tttT -p PID # system calls that are being made by the process. may slow down it a lot

tcpdump -i eth0 -w /tmp/out.tcpdump
netstat -s
nicstat
lsof -iTCP -sTCP:ESTABLISHED

pidstat -t #stats -t - per thread
pidstat -d #block I/O

swapon -s
```

Info:

* Linux Performance Tools, Brendan Gregg: https://www.youtube.com/watch?v=FJW8nGV4jxY
