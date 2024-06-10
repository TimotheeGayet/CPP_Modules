CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = PmergeMe

SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:%.cpp=.obj/%.o)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@

.obj/%.o : %.cpp Makefile PmergeMe.hpp
	@if [ ! -d .obj ]; then mkdir -p $(@D); fi
	$(CXX) $(CXXFLAGS) -c $< -IPmergeMe.hpp -o $@

.PHONY : clean
clean :
	rm -rf .obj

fclean : clean
	rm -rf $(TARGET)

re : fclean $(TARGET)
