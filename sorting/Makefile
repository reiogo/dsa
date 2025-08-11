filename=mergesort
makeandrun:
	make compiletest testrun

compiletest:
	g++ -DLOCAL_TESTING -Wall -std=c++11 ${filename}.cc -o ./bin/${filename}
testrun: ./bin/${filename}
	./bin/${filename} --exit

compile:
	g++ -Wall -std=c++11 ${filename}.cc -o ./bin/${filename}

run: ./bin/${filename}
	./bin/${filename}
