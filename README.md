for dub

gdb ./pipex
(gdb) set follow-fork-mode child
(gdb) set detach-on-fork off  # Optional
(gdb) break main
(gdb) break first_cmd_execute
(gdb) break second_cmd_execute
(gdb) run infile "ls -la" "tr 'a-z' 'A-Z'" outfile  # Your command
# ... gdb will stop at the breakpoint in main ...
(gdb) continue
# ... gdb will stop at the breakpoint in first_cmd_execute ...
(gdb) continue
# ... gdb will stop at the breakpoint in second_cmd_execute ...
(gdb) continue
# ... program continues ...
(gdb) quit
