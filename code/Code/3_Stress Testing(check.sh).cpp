// chmod u+x check.sh
// ./check.sh
set -e
g++ gen.cpp -o gen
g++ code.cpp -o code
g++ brute.cpp -o brute
for ((i = 1; ; ++i)); do
	echo "Passed on TestCase: " $i
	./gen $i > in
	./code < in > out1
	./brute < in > out2
	diff -Z out1 out2 || break
done
echo -e "WA on the following test:" 
cat in
echo -e "\nYour Answer is:"
cat out1
echo -e "\nCorrect answer is:"
cat out2
