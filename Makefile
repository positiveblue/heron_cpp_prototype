all: main

main: IPluggableSerializer.hpp Element.hpp Tuple.hpp Tweet.hpp User.hpp main.cpp
	clang++ -o main main.cpp -std=c++11
