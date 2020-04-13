```
brew install cmake
```

Observability tools:

```
perf # (aka perf_events), install linux-tools-common https://youtu.be/zrr2nUln9Kk?t=119

mpstat -P ALL #CPU load per processor
sudo strace -tttT -p PID # system calls that are being made by the process. may slow down it a lot
pidstat -t #stats -t - per thread
tiptop # IPC by process, can't use in cloud (needs PMCs enabled) https://youtu.be/zrr2nUln9Kk?t=184

tcpdump -i eth0 -w /tmp/out.tcpdump
netstat -s
nicstat
lsof -iTCP -sTCP:ESTABLISHED
# sar options: https://youtu.be/FJW8nGV4jxY?t=2953
sar -n DEV 1 #network
sar -n TCP,ETCP,DEV 1
iptraf #https://youtu.be/zrr2nUln9Kk?t=28

pidstat -d #block I/O
iostat -xmdz #IO for block devices excluding those that don't have anything happening
ss #socket stats
iotop #https://youtu.be/zrr2nUln9Kk?t=47

vmstat #memory
swapon -s
slabtop #https://youtu.be/zrr2nUln9Kk?t=70
pcstat #page cache residency by file https://youtu.be/zrr2nUln9Kk?t=96


# Other advanced tools: https://youtu.be/zrr2nUln9Kk?t=313
# Tools for all sorts of stuff: https://youtu.be/zrr2nUln9Kk?t=329
```

Benchmarking Tools 

* https://youtu.be/zrr2nUln9Kk?t=662

Info:

* Linux Performance Tools, Brendan Gregg: https://www.youtube.com/watch?v=FJW8nGV4jxY
