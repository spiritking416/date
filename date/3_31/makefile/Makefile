object=nqueen.o main.o place.o #定义变量
main:$(object)          #可执行文件依赖的中间文件
	g++ $(object) -o main -std=c++11
#nqueen.o:              #中间文件，可省略，make会自动推导，如果使用c++11，需要指明
#	g++ -c nqueen.cpp -std=c++11
#main.o:
#	g++ -c main.cpp -std=c++11
#place.o:
#	g++ -c place.cpp -std=c++11

.PHONY:clean
clean:
	-rm $(object) main
	
