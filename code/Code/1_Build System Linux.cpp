{
  "cmd" : ["ulimit -s 268435456;g++ -std=c++20 $file_name -o $file_base_name && timeout 4s ./$file_base_name<input.txt>output.txt"], 
  "selector" : "source.c",
  "shell": true,
  "working_dir" : "$file_path"
}