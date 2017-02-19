COUNTER=10
echo "Till what power of 10 would you like to run?"
read NUM
n=10
c=1
for ((i=1; i<=NUM; i++)); do ((n *= 10)); done
while [  $COUNTER -lt $n ]; do
	echo "Evaluating for 10e$c numbers."
	./runner.sh<<<$COUNTER >> result.txt 2>> result.txt
	let COUNTER=COUNTER*10
	let c=c+1
done
