CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g3

TARGET = animal

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS = $(SRCS:%.cpp=.obj/%.o)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@
 
.obj/%.o : %.cpp Animal.hpp Dog.hpp Cat.hpp Brain.hpp Makefile
	@if [ ! -d .obj ]; then 	mkdir -p $(@D); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -rf .obj

fclean : clean
	rm -rf $(TARGET)

re : fclean $(TARGET)